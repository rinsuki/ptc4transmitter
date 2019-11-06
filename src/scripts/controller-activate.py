# Push L+R → neutral, useful in activate controller screen of Switch
import time

neutral = bytes([
    0, # buttons
    0, # buttons
    8, #hat switch (8=neutral)
    0x7F, # stick L, X
    0x7F, # stick L, Y
    0x7F, # stick R, X
    0x7F, # stick R, Y
    0 # dummy?
])

def send(b):
    f = open("/dev/hidg0", "wb")
    f.write(b)
    f.flush()
    f.close()

    f = open("/dev/hidg0", "wb")
    f.write(neutral)
    f.flush()
    f.close()

send(bytes([
    0x10 + 0x20, # buttons 1 (L trigger + R trigger)
    0, # buttons 2
    8, #hat switch (8=neutral)
    0x7F, # stick L, X
    0x7F, # stick L, Y
    0x7F, # stick R, X
    0x7F, # stick R, Y
    0 # dummy?
]))

