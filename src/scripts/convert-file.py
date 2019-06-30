import sys
import os.path
stdout = open("/dev/stdout", "wb")

fp = sys.argv[1]
fn = os.path.basename(fp)

stdout.write(len(fn).to_bytes(1, "little"))
stdout.write(fn.encode("ascii"))

fsize = os.path.getsize(fp)
stdout.write(fsize.to_bytes(4, "little"))

stdout.write(open(fp, "rb").read())