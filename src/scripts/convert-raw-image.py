from PIL import Image
import sys

img = Image.open(sys.argv[1])
f = open("/dev/stdout", "wb")
f.write(img.width.to_bytes(2, "little"))
f.write(img.height.to_bytes(2, "little"))

for y in range(img.height):
    for x in range(img.width):
        a = img.getpixel((x, y))
        for c in a:
            f.write(c.to_bytes(1))