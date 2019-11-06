open("/dev/hidg0", "wb").write(bytes([
    0, # buttons
    0, # buttons
    8, #hat switch (8=neutral)
    0x7F, # stick L, X
    0x7F, # stick L, Y
    0x7F, # stick R, X
    0x7F, # stick R, Y
    0 # dummy?
]))