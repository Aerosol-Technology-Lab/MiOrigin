#!/bin/bash

python3.8 $ESPTOOL erase_region 0x210000 0x500000
python3.8 $ESPTOOL write_flash  0x210000 binaries/firmware.bin
