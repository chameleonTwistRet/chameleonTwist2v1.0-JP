#override for CommonSegDatabin to only use the passed rom_bytes and not a range

from splat.segtypes.common.databin import CommonSegDatabin
from splat.util import log, options

from pathlib import Path
from typing import Optional, TextIO
import zlib

class N64SegZ_databin(CommonSegDatabin):
    def write_bin(self, rom_bytes):
        binpath = self.bin_path()
        binpath.parent.mkdir(parents=True, exist_ok=True)

        decompress = zlib.decompress(rom_bytes[self.rom_start+8:self.rom_end])
        binpath.write_bytes(decompress)

        self.log(f"Wrote {self.name} to {binpath}")

    def write_asm_contents(self, rom_bytes, f: TextIO):
        binpath = self.bin_path()
        asm_label = options.opts.asm_function_macro
        if not self.is_text():
            asm_label = options.opts.asm_data_macro

        assert isinstance(self.rom_start, int)
        assert isinstance(self.rom_end, int)

        f.write(f"{self.get_section_asm_line()}\n\n")

        # Check if there's a symbol at this address
        sym = None
        vram = self.rom_to_ram(self.rom_start)
        if vram is not None:
            sym = self.get_symbol(vram, in_segment=True)

        if sym is not None:
            f.write(f"{asm_label} {sym.name}\n")
            sym.defined = True

        f.write(f'#{binpath}\n')
        f.write(f'.incbin "build/{binpath}.z"\n')

        if sym is not None:
            if self.is_text() and options.opts.asm_end_label != "":
                f.write(f"{options.opts.asm_end_label} {sym.name}\n")

            if sym.given_name_end is not None:
                if (
                    sym.given_size is None
                    or sym.given_size == self.rom_end - self.rom_start
                ):
                    f.write(f"{asm_label} {sym.given_name_end}\n")