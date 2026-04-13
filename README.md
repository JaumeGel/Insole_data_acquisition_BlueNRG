# BLE SensorBoard (BlueNRG-M2SA)

## Overview

This repository contains a complete demonstration firmware for STMicroelectronics BlueNRG-M2SA sensor board, implementing:

- Bluetooth Low Energy (BLE) peripheral with GAP/GATT services and characteristics
- Sensor acquisition via STM32 sensor board interface
- SPI communication with external sensor hardware

The code is based on the ST BlueNRG SensorDemo sample application and includes key modules in `User/`, `HAL/`, `Library/`, `Stack/`, and `Startup/`.

## Main Components

- `User/SensorDemo_main.c`: application entrypoint, stack initialization, event loop, sleep management
- `User/sensor.c`: BLE device initialization, service setup, connectable mode, sensor state machine (`APP_Tick`) and periodic updates
- `User/gatt_db.c`: GATT database definition (services/characteristics for sensor values)
- `User/STM32Sensor.c` and `User/STM32Sensor_hal.c`: sensor board low-level driver using SPI I/O
- `Library/BlueNRG1_*`: HAL and peripheral drivers for BlueNRG1
- `Stack/stack_user_cfg.c`: configuration for BLE stack

## Bluetooth Functionality

- BLE stack initialization (`BlueNRG_Stack_Initialization`)
- GAP peripheral role with advertising (`aci_gap_init`, `aci_gap_set_discoverable`)
- GATT server initialization and data update (`aci_gatt_init`, `aci_gatt_update_char_value_ext`)
- Authentication and bonding setup
- Connection event handling and hardware error resets

## SPI Functionality

- SPI channel initialized in `STM32Sensor_IO_Init()` from `STM32Sensor_hal.c`
- Sensor readings captured via `STM32Sensor_IO_Read()` in `APP_Tick`
- Sensor payload interpretation by `dataType`: resistive/capacitive modes
- BLE characteristic updates from sensor data using `Res_Update()` (and optional `Cap_Update`, `ResCap_Update`)

## Changing UUIDs

1. Open `User/gatt_db.c`.
2. Locate the service/characteristic UUID macros near the top, e.g.:
   - `COPY_RES_SERVICE_UUID`, `COPY_RES1_CHAR_UUID`, `COPY_RES2_CHAR_UUID`
   - `COPY_CAP_SERVICE_UUID`, `COPY_CAP1_CHAR_UUID`, ..., `COPY_CAP4_CHAR_UUID`
3. Update the 128-bit value bytes in the `COPY_UUID_128(...)` call to your new UUID values (in little-endian order as in the code).
4. Make sure matching characteristic handling remains consistent (e.g., `Res_Update`, `Cap_Update` if enabled).
5. Rebuild and flash.

Note: UUID changes are hardcoded in firmware and require device reprogramming.

## Build & Flash

1. Open project in WiSe Studio.
2. Configure target for BlueNRG-2, already configured.
3. Build and flash using existing `Release/makefile` or IDE generated project.

## Notes

- This README has been generated with the assistance of an AI (GitHub Copilot style). 

---

### Version

Project derived from ST BlueNRG-1 SensorDemo (2018) and updated in this workspace (2026).

---

## Contact

Author: JaumeGel  
Repository: https://github.com/JaumeGel/Insole_data_acquisition_BlueNRG