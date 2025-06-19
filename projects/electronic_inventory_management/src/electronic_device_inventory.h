#ifndef ELECTRONIC_DEVICE_INVENTORY_H
#define ELECTRONIC_DEVICE_INVENTORY_H

#include <stdbool.h>

// Device type
typedef enum deviceType {
    LAPTOP,
    SMARTPHONE,
    TABLET,
    HEADPHONES,
    OTHER
} deviceType;

// Device status
typedef enum deviceStatus {
    AVAILABLE,
    SOLD,
    IN_REPAIR,
    DISPOSED
} deviceStatus;

// Device Structure
typedef struct device {
    char name[50];
    int id;
    deviceType type;
    double price;
    deviceStatus status;
} device;

/*
 * @brief Removes a device from the inventory based on its unique identifier.
 * This involves finding the device and then shifting subsequent
 * devices in the array to fill the gap.
 * @param id The unique ID of the device to be removed from the inventory.
 * @return void This function does not return any value.
 * @note If the device is found, it decrements the internal 'deviceCount' variable.
 * Shifts elements in the 'inventory' array to the left, overwriting
 * the deleted device's position. Prints a confirmation or informative message.
 */
void deleteDevice(int id);

/*
 * @brief Resets the inventory, effectively removing all devices currently
 * stored within it.
 * @param void This function takes no parameters.
 * @return void This function does not return any value.
 * @note Sets the internal 'deviceCount' variable to 0. This makes the previously
 * stored device data inaccessible. Prints a confirmation message.
 */
void clearInventory(void);void clearInventory(void);

/*
 * @brief Adds a new electronic device to the inventory.
 * This function attempts to place a new device record into the
 * next available slot in the internal 'inventory' array.
 * @param name A pointer to a null-terminated string representing the
 * name or model of the device (e.g., "iPhone 15 Pro").
 * @param id A unique integer identifier for the device. It's crucial
 * that each device has a distinct ID for proper management.
 * @param type An enum value specifying the category of the device
 * (e.g., LAPTOP, SMARTPHONE, TABLET).
 * @param price The monetary value of the device.
 * @param status An enum value indicating the initial status of the device
 * (e.g., AVAILABLE, SOLD, IN_REPAIR).
 * @return bool Returns true if the device was successfully added to the inventory.
 * Returns false if the inventory is full (i.e., deviceCount
 * has reached MAX_DEVICES), and the device could not be added.
 * @note If successful, increments the internal 'deviceCount' variable.
 * Modifies the 'inventory' array by populating the next available
 * Device struct. Prints a confirmation or error message.
 */
bool addDevice(const char *name, int id, deviceType type,
               double price, deviceStatus status);

/*
 * @brief Prints the detailed information of a single electronic device
 * to the console.
 * @param device A constant pointer to the Device struct whose details
 * are to be displayed. Using 'const' here signifies that
 * this function will not modify the Device data it points to.
 * @return void This function does not return any value.
 * @note Prints formatted device information (ID, Name, Type, Price, Status)
 * to standard output. Prints an error message if the provided device
 * pointer is NULL.
 */
void displayDevice(const device *device);

/*
 * @brief Iterates through the entire inventory and displays the details
 * of all currently stored devices.
 * @param void This function takes no parameters.
 * @return void This function does not return any value.
 * @note Prints a header and footer for the inventory display. Calls
 * 'displayDevice()' for each device currently in the 'inventory'
 * array. Prints a message if the inventory is empty.
 */
void displayInventory(void);

/*
 * @brief Searches the inventory for a device with a specific unique identifier.
 * @param id The unique ID of the device to search for.
 * @return Device* A pointer to the Device struct within the 'inventory' array
 * if a matching ID is found. Returns NULL if no device with
 * the specified 'id' is found in the inventory.
 * @note This function only reads data and has no side effects on the inventory state.
 */
device* findDeviceById(int id);

/*
 * @brief Modifies the status of a specific electronic device.
 * @param device A pointer to the Device struct whose status is to be updated.
 * This pointer typically comes from a successful call to
 * 'findDeviceById()'.
 * @param newStatus The new enum value representing the desired status for
 * the device (e.g., SOLD, IN_REPAIR).
 * @return void This function does not return any value.
 * @note Modifies the 'status' member of the Device struct pointed to by 'device'.
 * Prints a confirmation or error message.
 */
void updateDeviceStatus(device *device, deviceStatus newStatus);

#endif
