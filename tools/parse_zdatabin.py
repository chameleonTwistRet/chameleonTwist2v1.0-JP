#!/usr/bin/env python3
"""
Chameleon Twist 2 - z_databin parser
Input: the already-decompressed .bin file output by z_databin_to_c.py

Usage:
    python3 parse_zdatabin.py <file.z_databin.bin>
"""

import sys
import struct
from pathlib import Path


SECTION_NAMES = {
    0x01: "mesh group table",
    0x02: "face records",
    0x03: "sub-mesh index table",
    0x0A: "section 0x0A",
    0x0B: "face group header",
    0x0C: "face data",
    0x1B: "section 0x1B",
    0x1E: "vertex array",
    0x43: "face record block",
    0xC9: "vertex array (large)",
}


def read_zdatabin(path):
    data = Path(path).read_bytes()
    print(f"File:              {Path(path).name}")
    print(f"File size:         0x{len(data):04X}  ({len(data)} bytes)")

    # first 4 bytes = internal total size (u32 BE)
    internal_size = struct.unpack_from(">I", data, 0)[0]
    print(f"Internal size:     0x{internal_size:04X}  ({internal_size} bytes)")
    print()

    # section table at offset 4: (u16 offset, u16 count) pairs, null-terminated
    print("Section table:")
    print(f"  {'#':<4} {'Offset':>8}  {'Count':>6}  Description")
    print(f"  {'-'*4}  {'-'*8}  {'-'*6}  {'-'*40}")

    sections = []
    pos = 8
    idx = 0
    while pos + 4 <= len(data):
        entry_offset, entry_count = struct.unpack_from(">HH", data, pos)
        pos += 4
        if entry_offset == 0 and entry_count == 0:
            print(f"  {'--':<4} [terminator]")
            break
        name = SECTION_NAMES.get(entry_count, f"unknown (type 0x{entry_count:02X})")
        print(f"  {idx:<4} 0x{entry_offset:04X}     {entry_count:>5}  {name}")
        sections.append((entry_offset, entry_count))
        idx += 1

    if not sections:
        print("  (no sections found)")
        return

    print()
    grp_offset, grp_count = sections[0]
    print(f"Mesh groups:  {grp_count} group(s) at offset 0x{grp_offset:04X}")

    if len(sections) >= 2:
        face_offset, face_count = sections[-2]
        print(f"Face records: {face_count} records at offset 0x{face_offset:04X}")

    vtx_offset, vtx_count = sections[-1]
    print(f"Vertices:     {vtx_count} vertices at offset 0x{vtx_offset:04X}")

    print()
    print("  First 4 vertices (x, y, z, flag, tu, tv, r, g, b, a):")
    for i in range(min(4, vtx_count)):
        vpos = vtx_offset + i * 16
        if vpos + 16 > len(data):
            break
        x, y, z, flag, tu, tv, r, g, b, a = struct.unpack_from(">hhhHhhBBBB", data, vpos)
        print(f"    [{i:>3}] xyz=({x:6},{y:6},{z:6})  flag=0x{flag:04X}  uv=({tu:6},{tv:6})  rgba=({r:3},{g:3},{b:3},{a})")

    print()
    print("Embedded ASCII strings (possible source filenames):")
    _scan_for_ascii(data)


def _scan_for_ascii(data, min_run=6):
    found = []
    run_start = None
    run = []
    for i, b in enumerate(data):
        if 0x20 <= b <= 0x7E:
            if run_start is None:
                run_start = i
            run.append(chr(b))
        else:
            if run and len(run) >= min_run:
                s = "".join(run)
                if any(c in s for c in [".", "/", "_"]):
                    found.append((run_start, s))
            run_start = None
            run = []
    if found:
        for offset, s in found:
            print(f"  0x{offset:04X}: {repr(s)}")
    else:
        print("  (none found)")


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <file.z_databin.bin>")
        sys.exit(1)
    read_zdatabin(sys.argv[1])