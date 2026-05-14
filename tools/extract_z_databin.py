#!/usr/bin/env python3
"""
Extract the first global OBJECT symbol from the .data section of a MIPS
big-endian 32-bit ELF .o file, trimmed to the exact symbol size.

Usage:
    python3 tools/extract_z_databin.py <input.o> <output.bin>
"""

import struct
import sys
from pathlib import Path

# 32-bit big-endian ELF layout constants
EI_CLASS  = 4  # 1 = 32-bit
EI_DATA   = 5  # 2 = big-endian
E_SHOFF   = 0x20
E_SHENTSIZE = 0x2E
E_SHNUM   = 0x30
E_SHSTRNDX = 0x32

SHT_SYMTAB = 2
STB_GLOBAL = 1
STT_OBJECT = 1


def _u16(d, off): return struct.unpack_from(">H", d, off)[0]
def _u32(d, off): return struct.unpack_from(">I", d, off)[0]


def _read_shdrs(elf):
    shoff     = _u32(elf, E_SHOFF)
    shentsize = _u16(elf, E_SHENTSIZE)
    shnum     = _u16(elf, E_SHNUM)
    return [
        dict(zip(
            ("name","type","flags","addr","offset","size","link","info","addralign","entsize"),
            struct.unpack_from(">IIIIIIIIII", elf, shoff + i * shentsize)
        ))
        for i in range(shnum)
    ]


def _section_name(elf, shdrs, shstrndx, sh):
    strtab_off = shdrs[shstrndx]["offset"]
    start = strtab_off + sh["name"]
    end = elf.index(b"\x00", start)
    return elf[start:end].decode()


def extract(elf_path: Path, out_path: Path):
    elf = elf_path.read_bytes()

    assert elf[:4] == b"\x7fELF", "not an ELF file"
    assert elf[EI_CLASS] == 1, "expected 32-bit ELF"
    assert elf[EI_DATA]  == 2, "expected big-endian ELF"

    shstrndx = _u16(elf, E_SHSTRNDX)
    shdrs = _read_shdrs(elf)

    # Locate .data and .symtab / .strtab sections
    data_sh = symtab_sh = strtab_sh = None
    for sh in shdrs:
        name = _section_name(elf, shdrs, shstrndx, sh)
        if name == ".data":
            data_sh = sh
        elif name == ".symtab":
            symtab_sh = sh
        elif name == ".strtab":
            strtab_sh = sh

    assert data_sh   is not None, ".data section not found"
    assert symtab_sh is not None, ".symtab section not found"
    assert strtab_sh is not None, ".strtab section not found"

    # Find the first GLOBAL OBJECT symbol that lives in .data
    entsize = symtab_sh["entsize"] or 16
    sym_size = sym_offset = None
    for off in range(symtab_sh["offset"], symtab_sh["offset"] + symtab_sh["size"], entsize):
        st_name, st_value, st_size, st_info, _st_other, st_shndx = \
            struct.unpack_from(">IIIBBB", elf, off)
        # Skip the extra byte so st_shndx is at the right offset (Elf32_Sym is 16 bytes)
        st_shndx = struct.unpack_from(">H", elf, off + 14)[0]
        bind = (st_info >> 4) & 0xF
        typ  =  st_info       & 0xF
        if bind == STB_GLOBAL and typ == STT_OBJECT and st_size > 0:
            sym_offset = st_value
            sym_size   = st_size
            break

    assert sym_size is not None, "no suitable GLOBAL OBJECT symbol found in .data"

    raw = elf[data_sh["offset"] : data_sh["offset"] + data_sh["size"]]
    out_path.write_bytes(raw[sym_offset : sym_offset + sym_size])
    print(f"extracted {sym_size} bytes → {out_path}")


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("usage: extract_z_databin.py <input.o> <output.bin>")
        sys.exit(1)
    extract(Path(sys.argv[1]), Path(sys.argv[2]))
