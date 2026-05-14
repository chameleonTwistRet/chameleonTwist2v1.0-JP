import zlib
import argparse

"""
import zlib
import struct
import argparse

# .bin.z format: [u32 uncompressed_size][u32 compressed_size][zlib data]

def encode(infile, outfile):
    raw = open(infile, "rb").read()
    compressed = zlib.compress(raw, -1)
    out = struct.pack(">II", len(raw), len(compressed)) + compressed
    open(outfile, "wb").write(out)

def decode(infile, outfile):
    data = open(infile, "rb").read()
    uncmp_size, cmp_size = struct.unpack_from(">II", data, 0)
    raw = zlib.decompress(data[8:8 + cmp_size])
    assert len(raw) == uncmp_size, f"size mismatch: got {len(raw)}, expected {uncmp_size}"
    open(outfile, "wb").write(raw)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="encode/decode CT2 zlib assets (.bin <-> .bin.z)")
    sub = parser.add_subparsers(dest="cmd", required=True)

    enc = sub.add_parser("encode", help="compress raw .bin -> .bin.z")
    enc.add_argument("infile")
    enc.add_argument("outfile")

    dec = sub.add_parser("decode", help="decompress .bin.z -> raw .bin")
    dec.add_argument("infile")
    dec.add_argument("outfile")

    args = parser.parse_args()
    if args.cmd == "encode":
        encode(args.infile, args.outfile)
    else:
        decode(args.infile, args.outfile)
"""

if __name__ == "__main__":
    parser = argparse.ArgumentParser("zlib zip")
    parser.add_argument("infile", help="in", type=str)
    parser.add_argument("outfile", help="out", type=str)
    args = parser.parse_args()


    inbytes = open(args.infile, "rb").read()
    outbytes = bytearray(zlib.compress(inbytes, -1))

    newbytes = int.to_bytes(len(inbytes), 4, "big")
    newbytes += int.to_bytes(len(outbytes), 4, "big")
    newbytes += outbytes

    #while len(newbytes) % 0x4 != 0:
    #    newbytes += int.to_bytes(0, 1, "big")

    open(args.outfile, "wb").write(newbytes)

