#!/usr/bin/env python3
"""Convert a QMK keymap.c to QMK keymap JSON format for use with keymap-drawer."""

import argparse
import json
import re
import sys


def parse_defines(source: str) -> dict[str, str]:
    """Extract #define name value macros (simple single-token or function-like values)."""
    defines: dict[str, str] = {}
    for match in re.finditer(
        r"^\s*#define\s+(\w+)\s+(.+)$", source, re.MULTILINE
    ):
        name = match.group(1)
        value = match.group(2).strip()
        # Skip include guards and non-keycode defines
        if name.startswith("_") and name.endswith("_"):
            continue
        defines[name] = value
    return defines


def expand_defines(keycode: str, defines: dict[str, str]) -> str:
    """Recursively expand #define macros in a keycode."""
    # Only expand if the keycode is a plain identifier matching a define
    if keycode in defines:
        expanded = defines[keycode]
        # Recurse in case of chained defines
        return expand_defines(expanded, defines)
    return keycode


def parse_layer_names(source: str) -> dict[str, int]:
    """Extract layer name -> index mapping from enum layers { ... }."""
    match = re.search(r"enum\s+layers\s*\{([^}]+)\}", source)
    if not match:
        return {}
    body = match.group(1)
    names: dict[str, int] = {}
    index = 0
    for entry in body.split(","):
        entry = re.sub(r"//.*", "", entry).strip()
        if not entry:
            continue
        if "=" in entry:
            name, val = entry.split("=", 1)
            name = name.strip()
            index = int(val.strip())
        else:
            name = entry.strip()
        names[name] = index
        index += 1
    return names


def extract_layout_name(source: str) -> str:
    """Extract the LAYOUT_xxx macro name from the first layer definition."""
    match = re.search(r"\]\s*=\s*(LAYOUT\w+)\s*\(", source)
    if not match:
        raise ValueError("Could not find LAYOUT macro in keymap")
    return match.group(1)


def extract_keymaps_block(source: str) -> str:
    """Extract the keymaps[][] = { ... } block."""
    match = re.search(
        r"const\s+uint16_t\s+PROGMEM\s+keymaps\s*\[\s*\]\s*\[.*?\]\s*\[.*?\]\s*=\s*\{",
        source,
    )
    if not match:
        raise ValueError("Could not find keymaps definition")
    start = match.end()
    depth = 1
    pos = start
    while pos < len(source) and depth > 0:
        if source[pos] == "{":
            depth += 1
        elif source[pos] == "}":
            depth -= 1
        pos += 1
    return source[start : pos - 1]


def split_layers(keymaps_block: str, layout_name: str) -> list[tuple[str, str]]:
    """Split keymaps block into (layer_name, keycode_string) pairs."""
    pattern = re.compile(
        r"\[\s*(\w+)\s*\]\s*=\s*" + re.escape(layout_name) + r"\s*\(", re.DOTALL
    )
    layers = []
    for match in pattern.finditer(keymaps_block):
        layer_name = match.group(1)
        start = match.end()
        depth = 1
        pos = start
        while pos < len(keymaps_block) and depth > 0:
            if keymaps_block[pos] == "(":
                depth += 1
            elif keymaps_block[pos] == ")":
                depth -= 1
            pos += 1
        keycode_str = keymaps_block[start : pos - 1]
        layers.append((layer_name, keycode_str))
    return layers


def parse_keycodes(keycode_str: str) -> list[str]:
    """Parse a comma-separated keycode string, respecting nested parentheses."""
    keycodes = []
    current = ""
    depth = 0
    for char in keycode_str:
        if char == "(":
            depth += 1
            current += char
        elif char == ")":
            depth -= 1
            current += char
        elif char == "," and depth == 0:
            token = current.strip()
            if token:
                keycodes.append(token)
            current = ""
        else:
            current += char
    token = current.strip()
    if token:
        keycodes.append(token)
    return keycodes


def resolve_layer_ref(name: str, layer_names: dict[str, int]) -> str:
    """Replace enum layer name references with numeric indices in keycodes."""
    return str(layer_names.get(name, name))


def resolve_keycode(keycode: str, layer_names: dict[str, int]) -> str:
    """Resolve layer name references within keycodes like LT(NAVI, KC_ENT)."""
    # Handle LT(layer, kc)
    lt_match = re.match(r"(LT)\((\w+),\s*(.+)\)", keycode)
    if lt_match:
        func, layer, kc = lt_match.groups()
        layer_resolved = resolve_layer_ref(layer, layer_names)
        return f"{func}({layer_resolved},{kc})"
    # Handle MO(layer)
    mo_match = re.match(r"(MO|TG|TO|TT|OSL)\((\w+)\)", keycode)
    if mo_match:
        func, layer = mo_match.groups()
        layer_resolved = resolve_layer_ref(layer, layer_names)
        return f"{func}({layer_resolved})"
    # Handle DF(layer)
    df_match = re.match(r"(DF)\((\w+)\)", keycode)
    if df_match:
        func, layer = df_match.groups()
        layer_resolved = resolve_layer_ref(layer, layer_names)
        return f"{func}({layer_resolved})"
    return keycode


def main() -> None:
    parser = argparse.ArgumentParser(description="Convert QMK keymap.c to keymap JSON")
    parser.add_argument("keymap_c", help="Path to keymap.c")
    parser.add_argument(
        "-kb", "--keyboard", required=True, help="Keyboard name (e.g. splitkb/halcyon/kyria)"
    )
    parser.add_argument("-km", "--keymap", required=True, help="Keymap name")
    parser.add_argument(
        "-l",
        "--layout",
        default=None,
        help="Layout macro name override (auto-detected if omitted)",
    )
    args = parser.parse_args()

    with open(args.keymap_c) as f:
        source = f.read()

    # Strip C-style comments (but keep content in strings)
    source_no_comments = re.sub(r"//.*", "", source)
    source_no_comments = re.sub(r"/\*.*?\*/", "", source_no_comments, flags=re.DOTALL)

    defines = parse_defines(source_no_comments)
    layer_names = parse_layer_names(source_no_comments)
    layout_name = args.layout or extract_layout_name(source_no_comments)
    keymaps_block = extract_keymaps_block(source_no_comments)
    raw_layers = split_layers(keymaps_block, layout_name)

    layers = []
    ordered_names = []
    for layer_name, keycode_str in raw_layers:
        keycodes = parse_keycodes(keycode_str)
        expanded = [expand_defines(kc, defines) for kc in keycodes]
        resolved = [resolve_keycode(kc, layer_names) for kc in expanded]
        layers.append(resolved)
        # Use the enum name, stripping leading underscores for cleaner display
        clean_name = layer_name.lstrip("_")
        ordered_names.append(clean_name)

    result = {
        "keyboard": args.keyboard,
        "keymap": args.keymap,
        "layout": layout_name,
        "layers": layers,
        "layer_names": ordered_names,
    }

    json.dump(result, sys.stdout, indent=2)
    sys.stdout.write("\n")


if __name__ == "__main__":
    main()
