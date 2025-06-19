#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "electronic_device_inventory.h"
#define MAX_DEVICES 5

/* Inventory using an array.
 * TODO: use a linked list for next implementation
 */
device inventory[MAX_DEVICES];
int deviceCount = 0; // Keeps track of how many devices are currently in the array

// Helper function to get DeviceType as string
const char* getDeviceTypeString(deviceType type) {
    switch (type) {
        case LAPTOP     : return "Laptop";
        case SMARTPHONE : return "Smartphone";
        case TABLET     : return "Tablet";
        case HEADPHONES : return "Headphones";
        case OTHER      : return "Other";
        default         : return "Unknown";
    }
}

// Helper function to get DeviceStatus as string
const char* getDeviceStatusString(deviceStatus status) {
    switch (status) {
        case AVAILABLE  : return "Available";
        case SOLD       : return "Sold";
        case IN_REPAIR  : return "In Repair";
        case DISPOSED   : return "Disposed";
        default         : return "Unknown";
    }
}

// Adds a device to the array
bool addDevice(const char *name, int id, deviceType type, double price, 
               deviceStatus status) {

    if (deviceCount >= MAX_DEVICES) {
        printf("Inventory is full. Cannot add more devices.\n");
        return false;
    }

    device *newDevice = &inventory[deviceCount]; // Get a pointer to the next available slot

    strncpy(newDevice->name, name, sizeof(newDevice->name) - 1);
    newDevice->name[sizeof(newDevice->name) - 1] = '\0'; // Ensure null-termination
    newDevice->id = id;
    newDevice->type = type;
    newDevice->price = price;
    newDevice->status = status;

    deviceCount++; // Increment the count of devices
    printf("Added device: %s (ID: %d)\n", newDevice->name, newDevice->id);

    return true;
}

// Displays the details of a single device (same as before)
void displayDevice(const device *device) {
    if (device == NULL) {
        printf("Device is NULL.\n");
        return;
    }
    printf("------------------------------------\n");
    printf("ID: %d\n", device->id);
    printf("Name: %s\n", device->name);
    printf("Type: %s\n", getDeviceTypeString(device->type));
    printf("Price: %.2f EUR\n", device->price);
    printf("Status: %s\n", getDeviceStatusString(device->status));
    printf("------------------------------------\n");
}

// Displays all devices in the inventory (iterates array)
void displayInventory() {
    printf("\n--- Current Inventory ---\n");
    if (deviceCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    for (int i = 0; i < deviceCount; i++) {
        displayDevice(&inventory[i]); // Pass address of struct in array
    }
    printf("--- End of Inventory ---\n");
}

// Finds a device by its ID (iterates array)
device* findDeviceById(int id) {
    for (int i = 0; i < deviceCount; i++) {
        if (inventory[i].id == id) {
            return &inventory[i]; // Return pointer to the found device in the array
        }
    }
    return NULL; // Device not found
}

// Updates the status of a device (same as before, operates on pointer)
void updateDeviceStatus(device *device, deviceStatus newStatus) {
    if (device != NULL) {
        printf("Updating status for device ID %d (%s) from %s to %s.\n",
               device->id, 
               device->name, 
               getDeviceStatusString(device->status), 
               getDeviceStatusString(newStatus));
        device->status = newStatus;
    } else {
        printf("Cannot update status: Device not found.\n");
    }
}

// Deletes a device from the array by its ID
void deleteDevice(int id) {
    int foundIndex = -1;
    for (int i = 0; i < deviceCount; i++) {
        if (inventory[i].id == id) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Device with ID %d not found for deletion.\n", id);
        return;
    }
    printf("Deleting device: %s (ID: %d)\n", inventory[foundIndex].name, inventory[foundIndex].id);

    // Shift elements to the left to fill the gap
    for (int i = foundIndex; i < deviceCount - 1; i++) {
        inventory[i] = inventory[i+1]; // Copy the next struct over the current one
    }
    memset(&inventory[deviceCount - 1], 0, sizeof(device));
    deviceCount--; // Decrement the count of devices
}

// Clears the inventory by resetting the count
void clearInventory() {
    printf("\nClearing inventory...\n");
    deviceCount = 0;
    memset(inventory, 0, MAX_DEVICES * sizeof(device));
    printf("Inventory cleared.\n");
}
