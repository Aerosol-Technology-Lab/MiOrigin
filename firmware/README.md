# MiOrigin Controller Firmware
Firmware for MiOrigin Controller

## Setup
1. Install PlatformIO for VS Code
1. Copy boards information from [./boards](boards/) to .platformio boards path

## Build and Flashing Firmware

### Intro
The MiOrigin controller requires two firmwares - a "factory" firmware and an "ota" firmware.

The ota firmware is the actual running firmware during normal operation. This firmware contains the functions that controls the bioaerosol collector. The factory firmware is a special bootloader firmware used to update the ota firmware.

In normal operation, the ota firmware will always boot over the factory firmware. If an update is available over BLE or a new ota firmware is present in the root directory of the MicroSD card, the ota firmware reboots to the factory firmware. The factory firmware flashes the new ota firmware, delete the old copy of the ota firmware in the MicroSD card at `/firmware` (if exists), then places a copy of the new firmware into that directory. If successful, the controller reboots to the newly flashed ota firmware.

### Note

### Flash Factory Firmware
1. Under PlatformIO Extension on the left sidebar, open Project Tasks
1. Select `Build` under `factory` firmware
1. Flash `factory` firwmare with either options:
    1. Connect laptop to control board with a USB-C cable
    1. Select `Upload` to flash directly to firmware
        - Choose this option if this is the first time flashing the board. This will update the correct partition table to the flash
    - add factory firmware with filename `factory.bin` to the root directory of the MicroSD card
        - Note: This is possible only if ota firmware has been previously flashed to the board. This is not possible with a board with no previous programming

### Flash OTA Firmware
1. Under PlatformIO Extension on the left sidebar, open Project Tasks
1. Build `ota` firwmare
1. Flash `factory` firmware with either options 
    - add ota firmware with filename `firmware.bin` to the root directory of the MicroSD card
    1. Connect laptop to control board with a USB-C cable
    1. flash with esptool `$ python3 esptool.py COM_PORT write_flash 0x110000 /path/to/firmware.bin`
        - NOTE: Address used for firmware in flash is `0x110000`. Verify beforing flashing by checking Offset address of `ota_0` in the [partition table](partition_table.csv)

### Pre-compiled firmwares
Pre-compiled firmwares are available at `todo: do this`

## Pipeline
- [x] TFT SPI LCD drivers
- [x] Post scripts that generates pre-compiled firmware/binaries
- [x] WiFi with keep awake
- [x] WiFi WPA
- [ ] WiFi WPA2 Enterprise
- [ ] BLE device settings
- [ ] Update over WiFi

## Known Issues
- Cannot communicate over RS-232. TX and RX pins are flipped between the rs3232 ic and D-sub port.
