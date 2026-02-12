#!/usr/bin/env python3
"""Generate 110x110 mono layer icons from Lucide SVGs.

Lucide icons are MIT licensed: https://github.com/lucide-icons/lucide
"""

import os
import io
import cairosvg
from PIL import Image

SIZE = 110
PADDING = 10  # px padding inside the icon
RENDER_SCALE = 4  # render at 4x then downscale for antialiasing

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

# Map output name to source SVG
ICONS = {
    "B": "house.svg",           # BASE - default layer
    "C": "puzzle.svg",          # CST1 - custom 1
    "G": "gamepad-2.svg",       # GAME - gaming
    "N": "hash.svg",            # NUMB - numbers & symbols
    "F": "square-function.svg", # FUNC - function keys
    "navi": "move.svg",         # NAVI - navigation
    "M": "music.svg",           # MDIA - light & media
    "S": "settings.svg",        # SYST - system
}


def svg_to_mono_png(svg_path, out_path, size=SIZE, padding=PADDING):
    """Convert a Lucide SVG to a white-on-black mono PNG at the target size."""
    with open(svg_path, "r") as f:
        svg_data = f.read()

    # Replace currentColor with white
    svg_data = svg_data.replace('stroke="currentColor"', 'stroke="white"')
    svg_data = svg_data.replace('fill="none"', 'fill="none"')
    svg_data = svg_data.replace('stroke-width="2"', 'stroke-width="2"')

    # Render SVG at high resolution (Lucide icons are 24x24 viewBox)
    render_size = size * RENDER_SCALE
    png_data = cairosvg.svg2png(
        bytestring=svg_data.encode(),
        output_width=render_size,
        output_height=render_size,
        background_color="black",
    )

    # Open and convert to grayscale
    img = Image.open(io.BytesIO(png_data)).convert("L")

    # Resize icon to fit within padded area
    inner = size - 2 * padding
    img = img.resize((inner, inner), Image.LANCZOS)

    # Threshold to pure black/white
    img = img.point(lambda x: 255 if x > 80 else 0)

    # Center on canvas
    canvas = Image.new("L", (size, size), 0)
    canvas.paste(img, (padding, padding))

    canvas.save(out_path)
    print(f"Saved {out_path}")


if __name__ == "__main__":
    for name, svg_file in ICONS.items():
        svg_path = os.path.join(SCRIPT_DIR, svg_file)
        out_path = os.path.join(SCRIPT_DIR, f"{name}.png")

        if not os.path.exists(svg_path):
            print(f"WARNING: {svg_path} not found, skipping")
            continue

        svg_to_mono_png(svg_path, out_path)
