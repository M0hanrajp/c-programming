#include "electronic_device_inventory.h"
#include <stdio.h>

int main(void) {

    // Add some devices to the inventory
    printf("--- Adding Devices ---\n");
    addDevice("Dell XPS 15", 101, LAPTOP, 1899.99, AVAILABLE);
    addDevice("iPhone 15 Pro", 102, SMARTPHONE, 1099.00, AVAILABLE);
    addDevice("iPad Air", 103, TABLET, 799.00, AVAILABLE);
    addDevice("Sony WH-1000XM5", 104, HEADPHONES, 349.50, AVAILABLE);
    addDevice("Gaming Mouse", 105, OTHER, 75.00, IN_REPAIR);
    addDevice("Smart Watch", 106, OTHER, 250.00, AVAILABLE); // Add one more to demonstrate limits

    // Display the initial inventory
    displayInventory();

    // Find and update a device
    printf("\n--- Finding and Updating Device ---\n");
    device *foundDevice = findDeviceById(102);
    if (foundDevice != NULL) {
        updateDeviceStatus(foundDevice, SOLD);
        displayDevice(foundDevice);
    } else {
        printf("Device with ID 102 not found.\n");
    }

    // Find a device that doesn't exist
    printf("\n--- Attempting to find non-existent device ---\n");
    foundDevice = findDeviceById(999);
    if (foundDevice == NULL) {
        printf("Device with ID 999 was not found, as expected.\n");
    }

    // Delete a device
    printf("\n--- Deleting a Device ---\n");
    deleteDevice(103); // Delete iPad Air

    // Display inventory after deletion
    displayInventory();

    // Attempt to delete a non-existent device
    printf("\n--- Attempting to delete non-existent device ---\n");
    deleteDevice(998);

    // Try adding more devices than MAX_DEVICES allows
    printf("\n--- Testing Inventory Capacity ---\n");
    addDevice("Extra Laptop 1", 107, LAPTOP, 1200.00, AVAILABLE);
    addDevice("Extra Laptop 2", 108, LAPTOP, 1300.00, AVAILABLE);
    addDevice("Extra Laptop 3", 109, LAPTOP, 1400.00, AVAILABLE); // This one will exceed MAX_DEVICES if MAX_DEVICES is 8
    addDevice("Extra Laptop 4", 110, LAPTOP, 1500.00, AVAILABLE); // This one will also fail

    displayInventory();

    // Clear all inventory before exiting
    clearInventory();
    displayInventory(); // Should show empty inventory
    return 0;
}
