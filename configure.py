#! /usr/bin/env python3

import argparse
import os
import shutil
import subprocess
import sys
from pathlib import Path
from typing import Dict, List, Set, Union

import ninja_syntax
import splat
import splat.scripts.split as split
from splat.segtypes.linker_entry import LinkerEntry

ROOT = Path(__file__).parent.resolve()
TOOLS_DIR = ROOT / "tools"

YAML_FILE = Path("chameleontwist2.jp.yaml")  # Convert to Path object
BASENAME = "chameleontwist2"
LD_PATH = f"{BASENAME}.ld"
ELF_PATH = f"build/{BASENAME}"
MAP_PATH = f"build/{BASENAME}.map"
PRE_ELF_PATH = f"build/{BASENAME}.elf"

COMMON_INCLUDES = "-I. -Iinclude -Isrc -Iinclude/PR"

#-Iinclude/PR -Iassets -Isrc

GAME_CC_DIR = f"$ASM_PROC $ASM_PROC_FLAGS {TOOLS_DIR}/ido_5.3/usr/lib/cc --$AS $ASFLAGS"
LIB_CC_DIR = f"$ASM_PROC $ASM_PROC_FLAGS {TOOLS_DIR}/ido_5.3/usr/lib/cc --$AS $ASFLAGS"
IDO71_CC_DIR = f"$ASM_PROC $ASM_PROC_FLAGS {TOOLS_DIR}/ido_7.1/usr/lib/cc --$AS $ASFLAGS"
LL_CC_DIR = f"$ASM_PROC $ASM_PROC_FLAGS {TOOLS_DIR}/ido_5.3/usr/lib/cc --$AS $ASFLAGS"
WARNINGS = "-fullwarn -verbose -Xcpluscomm -nostdinc -non_shared -Wab,-r4300_mul -D_LANGUAGE_C -DF3DEX_GBI -DNDEBUG -woff 649,838"
GAME_COMPILE_CMD = (
    f"{GAME_CC_DIR} {COMMON_INCLUDES} -- -c -G 0 {WARNINGS} {COMMON_INCLUDES} -mips2 -O2"
)

LIB_COMPILE_CMD = (
    f"{LIB_CC_DIR} {COMMON_INCLUDES} -- -c -G 0 {WARNINGS} {COMMON_INCLUDES} -mips2 -O2"
)

IDO71_COMPILE_CMD = (
    f"{IDO71_CC_DIR} {COMMON_INCLUDES} -- -c -G 0 {WARNINGS} {COMMON_INCLUDES} -mips2 -O2"
)

LL_COMPILE_CMD = (
    f"{GAME_CC_DIR} {COMMON_INCLUDES} -- -c -G 0 {WARNINGS} {COMMON_INCLUDES} -mips3 -32 -O1"
)

IO_COMPILE_CMD = (
    f"{GAME_CC_DIR} {COMMON_INCLUDES} -- -c -G 0 {WARNINGS} {COMMON_INCLUDES} -mips2 -O1"
)

# File-specific build rule overrides
# Key: source file path (relative to project root)
# Value: ninja rule name to use instead of the default
FILE_BUILD_OVERRIDES: Dict[str, str] = {
    # Examples:
    "src/io/pfschecker.c": "cc",           # Use io_cc instead of default cc
    
    # Add overrides here:
    # "path/to/your/file.c": "rule_name",
}

def exec_shell(command: List[str]) -> str:
    ret = subprocess.run(
        command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True
    )
    return ret.stdout


def clean():
    if os.path.exists(".splache"):
        os.remove(".splache")
    shutil.rmtree("asm", ignore_errors=True)
    shutil.rmtree("assets", ignore_errors=True)
    shutil.rmtree("build", ignore_errors=True)


def write_permuter_settings():
    with open("permuter_settings.toml", "w") as f:
        f.write(
            f"""compiler_command = "{GAME_COMPILE_CMD}"
assembler_command = "$ASFLAGS"
compiler_type = "gcc"

[preserve_macros]

[decompme.compilers]
"tools/ido_5.3/usr/lib/cc" = "ido_5.3"
"""
        )


def get_build_rule_for_file(src_path: Path, default_rule: str) -> str:
    """
    Check if there's an override rule for this specific file.
    Returns the override rule if found, otherwise returns the default rule.
    """
    # Convert to string and normalize path separators
    src_str = str(src_path).replace(os.sep, "/")
    
    # Check for exact match first
    if src_str in FILE_BUILD_OVERRIDES:
        return FILE_BUILD_OVERRIDES[src_str]
    
    # Check for matches without leading "./"
    src_clean = src_str.lstrip("./")
    if src_clean in FILE_BUILD_OVERRIDES:
        return FILE_BUILD_OVERRIDES[src_clean]
    
    return default_rule


def build_stuff(linker_entries: List[LinkerEntry]):
    built_objects: Set[Path] = set()

    def build(
        object_paths: Union[Path, List[Path]],
        src_paths: List[Path],
        task: str,
        variables: Dict[str, str] = {},
        implicit: List[str] = None,
        implicit_outputs: List[str] = [],
    ):
        if not isinstance(object_paths, list):
            object_paths = [object_paths]

        object_strs = [str(obj) for obj in object_paths]

        for object_path in object_paths:
            if object_path.suffix == ".o":
                built_objects.add(object_path)
            ninja.build(
                outputs=object_strs,
                rule=task,
                inputs=[str(s) for s in src_paths],
                variables=variables,
                implicit=implicit,
                implicit_outputs=implicit_outputs,
            )

    ninja = ninja_syntax.Writer(open(str(ROOT / "build.ninja"), "w"), width=9999)

    ninja.variable("ASM_PROC", "python3 tools/asm-processor/build.py")
    ninja.variable("ASM_PROC_FLAGS", "--input-enc=utf-8 --output-enc=euc-jp")
    ninja.variable(
        "ASFLAGS", f"mips-linux-gnu-as -EB -mtune=vr4300 -march=vr4300 -mabi=32"
    )

    # Rules
    cross = "mips-linux-gnu-"

    ld_args = f"-T chameleontwist2.ld -T undefined_syms_auto.txt -T undefined_syms.txt -Map $mapfile --no-check-sections"

    # .s -> .o
    ninja.rule(
        "as",
        description="as $in",
        command=f"iconv -f utf-8 -t euc-jp $in | {cross}as -no-pad-sections -EB -mtune=vr4300 -march=vr4300 -mabi=32 -Iinclude -o $out",
    )

    #for zlib compressed files
    ninja.rule(
        "zlib",
        description="zlib $in",
        command=f"python3 tools/zlib_zip.py $in $out",
    )

    ninja.rule(
        "cc",
        description="cc $in",
        command=f"{GAME_COMPILE_CMD} -o $out $in",
    )

    ninja.rule(
        "ido71_cc",
        description="cc $in",
        command=f"{IDO71_COMPILE_CMD} -o $out $in",
    )

    ninja.rule(
        "ll",
        command=f"({LL_COMPILE_CMD} -o $out $in) && (python3 {TOOLS_DIR}/set_o32abi_bit.py $out)",
        description="Compiling ll/*.c"
    )

    ninja.rule(
        "io_cc",
        command=f"{IO_COMPILE_CMD} -o $out $in",
        description="Compiling io/*.c",
        depfile="$out.d",  # Add the depfile specification here
        deps="gcc",
    )

    ninja.rule(
        "libcc",
        description="cc $in",
        command=f"{LIB_COMPILE_CMD} -o $out $in",
    )

    ninja.rule(
        "ld",
        description="link $out",
        command=f"{cross}ld {ld_args} -o $out",
    )

    ninja.rule(
        "sha1sum",
        description="sha1sum $in",
        command="sha1sum -c $in && touch $out",
    )

    ninja.rule(
        "elf",
        description="elf $out",
        command=f"{cross}objcopy $in $out -O binary",
    )

    for entry in linker_entries:
        seg = entry.segment

        if seg.type[0] == ".":
            continue

        if entry.object_path is None:
            continue

        if isinstance(seg, splat.segtypes.common.asm.CommonSegAsm) or isinstance(
            seg, splat.segtypes.common.data.CommonSegData
        ):
            # Determine the default rule
            default_rule = "as"
            
            # Check for override and use the first source path for override lookup
            if entry.src_paths:
                rule_to_use = get_build_rule_for_file(entry.src_paths[0], default_rule)
            else:
                rule_to_use = default_rule
                
            build(entry.object_path, entry.src_paths, rule_to_use)
            
        elif isinstance(seg, splat.segtypes.common.c.CommonSegC):
            # Determine the default rule based on path
            default_rule = "cc"  # Default fallback
            
            if any(str(src_path).startswith("src/lib/") for src_path in entry.src_paths):
                default_rule = "libcc"
            elif any(str(src_path).startswith("src/ido_71/") for src_path in entry.src_paths):
                default_rule = "ido71_cc"
            elif any(str(src_path).startswith("src/ll/") for src_path in entry.src_paths):
                default_rule = "ll"
            elif any(str(src_path).startswith("src/io/") for src_path in entry.src_paths):
                default_rule = "io_cc"
            
            # Check for override and use the first source path for override lookup
            if entry.src_paths:
                rule_to_use = get_build_rule_for_file(entry.src_paths[0], default_rule)
            else:
                rule_to_use = default_rule
                
            build(entry.object_path, entry.src_paths, rule_to_use)
            
        elif isinstance(seg, splat.segtypes.common.databin.CommonSegDatabin):
            if str(seg.type) == "z_databin":
                #get the original file and the incbin file
                l = open(entry.src_paths[0], "r").readlines()
                x = 0
                outfile = ""
                while x < len(l):
                    if l[x].find("incbin") != -1:
                        infile = l[x-1].split("#")[-1].strip()
                        outfile = l[x].split('"')[-2].strip()
                        build(Path(outfile), [Path(infile)], "zlib")
                        break
                    x += 1
                    
                # Determine rule (default is "as")
                default_rule = "as"
                if entry.src_paths:
                    rule_to_use = get_build_rule_for_file(entry.src_paths[0], default_rule)
                else:
                    rule_to_use = default_rule
                    
                #then just build the assembly (the binary) with the compressed binary as a dependency
                build(entry.object_path, entry.src_paths, rule_to_use, [], [outfile])
            else:
                # Determine rule (default is "as")
                default_rule = "as"
                if entry.src_paths:
                    rule_to_use = get_build_rule_for_file(entry.src_paths[0], default_rule)
                else:
                    rule_to_use = default_rule
                    
                build(entry.object_path, entry.src_paths, rule_to_use)
        else:
            print(f"ERROR: Unsupported build segment type {seg.type}")
            sys.exit(1)

    ninja.build(
        PRE_ELF_PATH,
        "ld",
        LD_PATH,
        implicit=[str(obj) for obj in built_objects],
        variables={"mapfile": MAP_PATH},
    )

    ninja.build(
        ELF_PATH,
        "elf",
        PRE_ELF_PATH,
    )

    ninja.build(
        ELF_PATH + ".ok",
        "sha1sum",
        "checksum.sha1",
        implicit=[ELF_PATH],
    )


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Configure the project")
    parser.add_argument(
        "-c",
        "--clean",
        help="Clean extraction and build artifacts",
        action="store_true",
    )
    args = parser.parse_args()

    if args.clean:
        clean()

    split.main([YAML_FILE], modes="all", verbose=False)

    linker_entries = split.linker_writer.entries

    build_stuff(linker_entries)

    write_permuter_settings()