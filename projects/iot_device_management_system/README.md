<h1 align="center">Project Title: IoT Device Management System</h1>

## Project Description

The aim is to build an **IoT Device Management System** that simulates managing multiple IoT devices in a network. The system will involve dynamic memory management, pointer qualifiers, multilevel pointers, and function pointers to handle device data efficiently.

The project is understand practical use cases of pointers in real-world scenarios, such as:
1. Managing dynamically allocated memory for device data.
2. Using constant pointers and pointers to constants for ensuring data safety.
3. Applying pointer arithmetic to traverse device data.
4. Using function pointers for modular operation execution.

---

### Build & run the project

`make` is required to build the project.
- `make build` to build the project
- `make run` to run the program.
- `make clean` removes all build files.:w

Program output is stored in log file,
```bash
$ make run
././build/iot_system_management | tee ./log/iot_system_management.log
----------------------
[INFO]: Device Details
----------------------
[INFO]: ID: 0x3, Name: Humidity     , Status:  OFFLINE at 0x5557472fd2a0
[INFO]: ID: 0x4, Name: Ultrasound   , Status:  OFFLINE at 0x5557472fd2d8
[INFO]: ID: 0x2, Name: pressure     , Status:  OFFLINE at 0x5557472fd310
[INFO]: ID: 0x5, Name: Accelerometer, Status:  OFFLINE at 0x5557472fd348
[INFO]: ID: 0x6, Name: Motion       , Status:  OFFLINE at 0x5557472fd380
[INFO]: ID: 0x1, Name: Temperature  , Status:   ONLINE at 0x5557472fd3b8
[INFO]: ID: 0x7, Name: Touch        , Status:  OFFLINE at 0x5557472fd3f0
[INFO]: Device ID: 0x6 has been updated as ONLINE
[INFO]: Device ID: 0x7 has been updated as ONLINE
[INFO]: Motion device found at 0x5557472fd380 and is assigned to 0x7fff5289db20
[INFO]: Deleting Device ID: 0x7 ...
```
### Objectives
1. Build an IoT system that manages a dynamic list of devices.
2. Use pointers with various qualifiers (`const`, `*`, `**`) for data handling.
3. Implement pointer arithmetic for traversing device data.
4. Use function pointers to modularize operations like adding, updating, and retrieving device information.
5. Simulate IoT-specific operations like device discovery and status updates.

---

### Core Functionalities

#### a. **Dynamic Device Array**
   - Function: `struct Device* allocateDevices(int count)`
     - Dynamically allocate memory for an array of devices.
     - Demonstrates: Pointer to memory, dynamic allocation.

#### b. **Add a Device**
   - Function: `void addDevice(struct Device** devices, int* count, int id, const char* name, bool status)`
     - Use a double pointer (`struct Device**`) to dynamically grow the array.
     - Use `const char*` to demonstrate pointers to constants.
     - Demonstrates: Double pointers, pointers to constants, dynamic memory reallocation.

#### c. **Update Device Status**
   - Function: `void updateDeviceStatus(struct Device* devices, int count, int id, bool status)`
     - Search for a device by ID and update its status.
     - Demonstrates: Pointer arithmetic (to traverse the array).

#### d. **Search for a Device**
   - Function: `const struct Device* findDevice(const struct Device* devices, int count, int id)`
     - Use a constant pointer to ensure immutability while searching.
     - Return a pointer to the found device or `NULL` if not found.
     - Demonstrates: Constant pointers.

#### e. **Monitor All Devices**
   - Function: `void printDevices(const struct Device* devices, int count)`
     - Traverse the array using pointer arithmetic and print device details.
     - Demonstrates: Pointer arithmetic.

#### f. **Delete a Device**
   - Function: `void deleteDevice(struct Device** devices, int* count, int id)`

#### g. **Function Pointers for Operations**
   - Define a type: `typedef void (*DeviceOperation)(struct Device*, int);`
   - Function: `void executeOperation(DeviceOperation op, struct Device* devices, int count)`
     - Use function pointers to execute operations like printing or updating device data.
     - _has not been done yet_

---

### Project Structure

All files after project has been built.
```bash
$ tree .
.
├── Makefile
├── build
│   ├── iot_system_core_functions.o
│   ├── iot_system_management
│   └── main.o
├── log
│   └── iot_system_management.log
└── src
    ├── iot_system_core_functions.c
    ├── iot_system_core_functions.h
    └── main.c
```
---

### IoT-Specific Features
1. **Simulating Device Discovery**:
   - Add a feature to simulate the discovery of devices using a random generator.
   - Use function pointers to handle discovered devices (e.g., register them in the system).

2. **Simulating Network Updates**:
   - Periodically update device statuses (e.g., online to offline) using a timer or loop.

4. **Build a CLI Application**:
- Create a command-line interface for the user to:
  - Add a device.
  - Update device status.
  - Search for a device.
  - Delete a device.
  - Monitor all devices.

5. **Test and Debug**
- Test with various scenarios, including edge cases like:
  - Adding devices with duplicate IDs.
  - Searching for non-existent devices.
  - Deleting devices from an empty list.

---

### Tools and Resources
- **Debugger**: Use GDB to step through pointer operations.
- **Memory Checker**: Use Valgrind to identify memory leaks.
- **Reference Tools**:
  - [cdecl.org](https://cdecl.org/) to interpret declarations.
  - Online pointer visualization tools for better understanding.

---

### Todo:
- Makefile for building the project.
- Function pointer to execute the functions.
     - Use a double pointer (`struct Device**`) to shrink the array.
     - Demonstrates: Double pointers, dynamic memory deallocation.
