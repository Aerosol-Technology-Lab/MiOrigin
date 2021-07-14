#!/bin/bash

python3.8 $ESPTOOL erase_region 0x10000 0x200000
python3.8 $ESPTOOL write_flash  0x10000 binaries/factory.bin
