#!/usr/bin/env python3
"""Generate 75x105 mono layer icons from Lucide SVGs.

Lucide icons are MIT licensed: https://github.com/lucide-icons/lucide
"""

import os
import io
import cairosvg
from PIL import Image

WIDTH = 75
HEIGHT = 105
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


def svg_to_mono_png(svg_path, out_path, width=WIDTH, height=HEIGHT, padding=PADDING):
    """Convert a Lucide SVG to a white-on-black mono PNG at the target size."""
    with open(svg_path, "r") as f:
        svg_data = f.read()

    # Replace currentColor with white, increase stroke width for visibility
    svg_data = svg_data.replace('stroke="currentColor"', 'stroke="white"')
    svg_data = svg_data.replace('fill="none"', 'fill="none"')
    svg_data = svg_data.replace('stroke-width="2"', 'stroke-width="2"')

    # Render SVG as square at high resolution (Lucide icons are 24x24 viewBox)
    render_size = max(width, height) * RENDER_SCALE
    png_data = cairosvg.svg2png(
        bytestring=svg_data.encode(),
        output_width=render_size,
        output_height=render_size,
        background_color="black",
    )

    # Open and convert to grayscale
    img = Image.open(io.BytesIO(png_data)).convert("L")

    # Resize icon to fit within padded area, maintaining aspect ratio
    inner_w = width - 2 * padding
    inner_h = height - 2 * padding
    icon_size = min(inner_w, inner_h)  # square icon
    img = img.resize((icon_size, icon_size), Image.LANCZOS)

    # Threshold to pure black/white
    img = img.point(lambda x: 255 if x > 80 else 0)

    # Center on canvas
    canvas = Image.new("L", (width, height), 0)
    x_offset = (width - icon_size) // 2
    y_offset = (height - icon_size) // 2
    canvas.paste(img, (x_offset, y_offset))

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
