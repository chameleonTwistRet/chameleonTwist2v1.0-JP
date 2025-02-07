import zlib
import argparse

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

