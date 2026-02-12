#!/usr/bin/env python3
"""Generate mono modifier icons from Lucide SVGs for CAGS home row mods.

Lucide icons are MIT licensed: https://github.com/lucide-icons/lucide
"""

import os
import io
import cairosvg
from PIL import Image

SIZE = 52
PADDING = 4  # px padding inside the icon
RENDER_SIZE = SIZE * 4  # render at 4x then downscale for antialiasing

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

# Lucide SVGs use stroke="currentColor". Replace with white, add black background.
ICONS = {
    "ctrl": "chevron-up.svg",
    "alt": "option.svg",
    "gui": "command.svg",
    "shift": "arrow-big-up.svg",
    "caps": "arrow-big-up-dash.svg",
}


def svg_to_mono_png(svg_path, out_path, size=SIZE, padding=PADDING):
    """Convert a Lucide SVG to a white-on-black mono PNG at the target size."""
    with open(svg_path, "r") as f:
        svg_data = f.read()

    # Replace currentColor with white, increase stroke width for visibility
    svg_data = svg_data.replace('stroke="currentColor"', 'stroke="white"')
    svg_data = svg_data.replace('fill="none"', 'fill="none"')
    svg_data = svg_data.replace('stroke-width="2"', 'stroke-width="2.5"')

    # Render SVG to PNG at high resolution
    png_data = cairosvg.svg2png(
        bytestring=svg_data.encode(),
        output_width=RENDER_SIZE,
        output_height=RENDER_SIZE,
        background_color="black",
    )

    # Open, resize to target with padding, convert to grayscale then 1-bit
    img = Image.open(io.BytesIO(png_data)).convert("L")

    # Crop to content area (remove SVG padding from viewBox)
    inner = size - 2 * padding
    img = img.resize((inner, inner), Image.LANCZOS)

    # Threshold to pure black/white
    img = img.point(lambda x: 255 if x > 80 else 0)

    # Place on black canvas with padding
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
