#!/bin/bash

python3.8 $ESPTOOL erase_region 0x8000 0x1000
python3.8 $ESPTOOL write_flash  0x8000 binaries/binary_partitions.bin
