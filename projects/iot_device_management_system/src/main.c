/* Main driver, Handles execution of all operations. 
 */

#include "iot_system_core_functions.h"
#include <stdio.h>
#define ONLINE  1
#define OFFLINE 0

int main(void) {
    int count = 0;
    // adding devices
    addDevice(&deviceDatabase, &count, 0x3,      "Humidity", OFFLINE);
    addDevice(&deviceDatabase, &count, 0x4,    "Ultrasound", OFFLINE);
    addDevice(&deviceDatabase, &count, 0x2,      "pressure", OFFLINE);
    addDevice(&deviceDatabase, &count, 0x5, "Accelerometer", OFFLINE);
    addDevice(&deviceDatabase, &count, 0x6,        "Motion", OFFLINE);
    addDevice(&deviceDatabase, &count, 0x1,   "Temperature",  ONLINE);
    addDevice(&deviceDatabase, &count, 0x7,         "Touch", OFFLINE);

    // print the devices
    printDevices(deviceDatabase, count);

    // updating device status for Touch and Motion as online
    updateDeviceStatus(deviceDatabase, count, 0x6, ONLINE);
    updateDeviceStatus(deviceDatabase, count, 0x7, ONLINE);

    // search for a device (device discovery)
    const device *getMotionDevice = findDevice(deviceDatabase, count, 0x6);
    if(getMotionDevice)
        printf("[INFO]: Motion device found at %p and is assigned to %p\n", getMotionDevice, &getMotionDevice);

    // Delete Touch device
    deleteDevice(&deviceDatabase, &count, 0x7);
    printDevices(deviceDatabase, count);

    return 0;
}
