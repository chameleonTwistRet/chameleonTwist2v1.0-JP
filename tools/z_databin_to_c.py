#!/usr/bin/env python3
"""
Convert a decoded z_databin .bin to an editable .c source file.

Usage:
    python3 tools/z_databin_to_c.py assets/SkyLandData/island2.z_databin.bin

Once the .c exists, configure.py will automatically use the compile pipeline
instead of the raw-bin pipeline when building.
"""

import sys
from pathlib import Path

BYTES_PER_ROW = 16

SRC_ASSETS = Path("src/assets")


def bin_to_c(bin_path: Path, sym_name: str) -> Path:
    data = bin_path.read_bytes()

    rel = bin_path.relative_to("assets")
    c_path = SRC_ASSETS / rel.parent / (Path(rel.name).stem + ".c")

    rows = []
    for i in range(0, len(data), BYTES_PER_ROW):
        chunk = data[i : i + BYTES_PER_ROW]
        rows.append("    " + ", ".join(f"0x{b:02X}" for b in chunk) + ",")

    lines = [
        '#include "common.h"',
        "",
        f"u8 {sym_name}[] = {{",
        *rows,
        "};",
        "",
    ]

    c_path.parent.mkdir(parents=True, exist_ok=True)
    c_path.write_text("\n".join(lines), encoding="utf-8")
    print(f"wrote {c_path}  ({len(data)} bytes, sym={sym_name})")
    return c_path


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("usage: z_databin_to_c.py <asset.z_databin.bin> [sym_name]")
        sys.exit(1)

    bin_path = Path(sys.argv[1])
    if not bin_path.exists():
        print(f"error: {bin_path} not found")
        sys.exit(1)

    sym_name = sys.argv[2] if len(sys.argv) >= 3 else bin_path.stem.split(".")[0]

    bin_to_c(bin_path, sym_name)
