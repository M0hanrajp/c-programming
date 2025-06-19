## **Program Design: Electronic Device Inventory System**

A simple management system that helps in creating, reading, updating & deleting a device.

**1. Enums: `DeviceType` and `DeviceStatus`**

* `DeviceType`: This enum will categorize our electronic devices (e.g., `LAPTOP`, `SMARTPHONE`, `TABLET`, `HEADPHONES`, `OTHER`). This makes the code more readable and less error-prone than using magic numbers or strings for device types.
* `DeviceStatus`: This enum will indicate the current status of a device (e.g., `AVAILABLE`, `SOLD`, `IN_REPAIR`, `DISPOSED`).

>_This program is was created to learn how enums can be used_

### Build and run 

`make` is required to build the project.
- `make build` to build the project
- `make run` to run the program.
- `make clean` removes all build files.:w

### Project tree

```bash
.
├── Makefile
├── README.md
├── build
│   ├── electronic_device_inventory
│   ├── electronic_device_inventory.o
│   └── main.o
├── log
│   └── electronic_device_inventory.log
└── src
    ├── electronic_device_inventory.c
    ├── electronic_device_inventory.h
    └── main.c
```
