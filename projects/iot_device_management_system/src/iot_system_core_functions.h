#ifndef IOT_CORE_FUNCTIONS_H
#define IOT_CORE_FUNCTIONS_H

#include <stdbool.h>

// device data representation
typedef struct {
    int id;
    char name[50];
    bool status; // 1 -> online, 0 -> offline
} device;

// Dynamic array that contains devices
extern device *deviceDatabase;

// function prototype declarations for core functions
void printDevices(const device* deviceDB, int count);
void updateDeviceStatus(device* deviceDB, int count, int id, bool status);
void addDevice(device **devices, int *count, int id, const char *name, bool status);
void deleteDevice(device** deviceDB, int* count, int id);
device *allocateDevice(int *count);
const device* findDevice(const device* deviceDB, int count, int id);

#endif
