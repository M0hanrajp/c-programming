/* Source code - IOT core functionalities
 * Contains function definitions of the functions mentioned in README.md 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iot_system_core_functions.h"

// Dynamic array that contains devices
device *deviceDatabase = NULL;

// Core functionalities

/* Dynamic array - database to store devices
 * sizeof(device) amount of memory is allcoated for each device.
 * to add new device, realloc extends array by 1 * sizeof(device).
 * function returns the pointer to the allocated memory */
device *allocateDevice(int *count) {
    device *deviceDatabaseBackup = NULL;
    if(*count < 1) { // first device
        *count = 1;
        deviceDatabase = (device *)calloc(*count, sizeof(device));
        if(deviceDatabase != NULL)
            return deviceDatabase;
        else
            printf("[ERR]: Memory allocation failed for deviceDatabase\n");
    } else {
        *count += 1;
         deviceDatabaseBackup = (device *)realloc(deviceDatabase, *count * sizeof(device));
        if(deviceDatabaseBackup != NULL) {
            deviceDatabase = deviceDatabaseBackup;
            return deviceDatabase;
        } else
            printf("[ERR]: Memory reallocation failed for deviceDatabase\n");
    }
    return 0;
}

/* Adding a device
 * Allocate the memory for a device,copy function parameters into database. */
void addDevice(device **devices, int *count, int id, const char *name, bool status) {
    *devices = allocateDevice(count);
    (*devices)[*count - 1].id = id;
    strcpy((*devices)[*count - 1].name, name);
    (*devices)[*count - 1].status = status;
}

/* Update device status
 * traverse through array, find device by id, update the status */
void updateDeviceStatus(device* deviceDB, int count, int id, bool status) {
    for(int i = 0; i < count; i++) {
        if(id == deviceDB[i].id) {
            deviceDB[i].status = status;
            printf("[INFO]: Device ID: 0x%X has been updated as %s\n", 
                    deviceDB[i].id,
                    deviceDB[i].status == 0 ? "OFFLINE" : "ONLINE");
        }
    }
}

/* Search for a device, Return a pointer to the found device or NULL if not found. */
const device* findDevice(const device* deviceDB, int count, int id) {
    for(int i = 0; i < count; i++)
        if(id == deviceDB[i].id) return &deviceDB[i];
    return NULL;
}

/* Device monitoring, print the device details */
void printDevices(const device* deviceDB, int count) {
    printf("----------------------\n[INFO]: Device Details\n----------------------\n");
    for(int i = 0; i < count; i++)
         printf("[INFO]: ID: 0x%X, Name: %-13s, Status: %8s at %p\n", 
                 /* -13 number should be based on the largest string to adjust alignment */
                 deviceDB[i].id,
                 deviceDB[i].name,
                 deviceDB[i].status == 0 ? "OFFLINE" : "ONLINE",
                 deviceDB + i);
}

/* Delete a device,
 * if valid device found, copy current details to a new database by skipping the matched device.
 * free and deallocate the old database, assign the new database address to the old database. */
void deleteDevice(device** deviceDB, int* count, int id) {

    // check for id, if device found, then proceed to delete the device
    bool deviceFound = false;
    for(int i = 0; i < *count; i++) {
        if((*deviceDB)[i].id == id)
            deviceFound = true;
    }

    device *newDeviceDatabase = NULL;
    if(deviceFound) {
        // allocate memory of 1 struct object less
        newDeviceDatabase = calloc((*count - 1), sizeof(device));
        device *temp = calloc(1, sizeof(device));
        int dbInstance = 0;
        for(int i = 0; i < *count; i++) {
            memset(temp, 0, sizeof(device));
            temp->id = (*deviceDB)[i].id;
            // copy struct members for valid id
            if(temp->id == id)
                continue;
            strcpy(temp->name, (*deviceDB)[i].name);
            temp->status = (*deviceDB)[i].status;
            newDeviceDatabase[dbInstance++] = *temp;
        }

        printf("[INFO]: Deleting Device ID: 0x%X ... \n", id);
        updateDeviceStatus(*deviceDB, *count, id, 0); // 0 -> device is offline

        // allocate 0 to memory space & free the original database
        memset(*deviceDB, 0, *count * sizeof(device));
        free(*deviceDB); 
        *deviceDB = NULL;
        deviceDatabase = NULL;

        // assign new address to original database
        deviceDatabase = newDeviceDatabase;
        --*count;

        printf("[INFO]: Device ID: 0x%X has been deleted !, current devices = %2d\n", id, *count);
        free(temp);
        temp = NULL;

        } else {
            printf("[INFO]: Device ID not found !, cannot delete sensor with ID: 0x%X\n", id);
        }
}
