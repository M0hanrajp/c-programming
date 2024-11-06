/*
Challenge: Bit Field Manipulator

Create a function that manages a 32-bit field where:
- Bits 0-7 represent a temperature (0-255)
- Bits 8-15 represent a humidity percentage (0-100)
- Bits 16-23 represent a pressure value (0-255)
- Bits 24-31 represent status flags:
  - Bit 24: Temperature warning (1 if temp > 30)
  - Bit 25: Humidity warning (1 if humidity > 80)
  - Bit 26: Pressure warning (1 if pressure > 200)
  - Bits 27-31: Reserved for future use

Requirements:
1. Implement the following functions:
   - set_temperature(uint32_t* field, uint8_t temp)
   - set_humidity(uint32_t* field, uint8_t humidity)
   - set_pressure(uint32_t* field, uint8_t pressure)
   - get_temperature(uint32_t field)
   - get_humidity(uint32_t field)
   - get_pressure(uint32_t field)
   - update_warning_flags(uint32_t* field)
   - is_any_warning_active(uint32_t field)
2. Each function should use only bitwise operations
3. Warning flags should automatically update when values change
*/
#include <stdio.h>
#include <stdint.h>

void displayBinary(uint32_t field);
void set_temperature(uint32_t* field, uint8_t temp);
uint32_t get_temperature(uint32_t field);
void set_humidity(uint32_t* field, uint8_t humidity);
uint32_t get_humidity(uint32_t field);

int main(void) {
    uint32_t sensor_field = 0;
    set_temperature(&sensor_field, 35);displayBinary(sensor_field);
    printf("Temperature :: %u\n", get_temperature(sensor_field));
    set_humidity(&sensor_field, 45);displayBinary(sensor_field);
    printf("Humidity :: %u%%\n", get_humidity(sensor_field));
    return 0;
}

void displayBinary(uint32_t field) {
    uint32_t andResult = 0;
    printf("[DEBUG_LOG] Binary representation of sensor_field:: ");
    for(int bitPosition = 31; bitPosition >= 0; bitPosition--) {
        andResult = field & (1 << bitPosition);
        andResult ? printf("1") : printf("0");
    }
    printf("\n");
}

void set_temperature(uint32_t* field, uint8_t temp) {
    uint8_t andResult = 0, bitValue = 0;
    *field &= ~(0xff); // clear the previous set bits
    for(int bitPosition = 7; bitPosition >= 0; bitPosition--) {
        andResult = temp & (1 << bitPosition);
        bitValue = (andResult) ? 1 : 0;
        *field |= (bitValue << bitPosition);
    }
}

uint32_t get_temperature(uint32_t field) {
    uint32_t intTemperatureValue = 0, andResult = 0, bitValue = 0;
    for(int bitPosition = 7; bitPosition >= 0; bitPosition--) {
        andResult = field & (1 << bitPosition);
        bitValue = (andResult) ? 1 : 0;
        intTemperatureValue |= (bitValue << bitPosition);
    }
    return intTemperatureValue;
}

void set_humidity(uint32_t* field, uint8_t humidity) {
    uint8_t andResult = 0, bitValue = 0;
    *field &= ~(0xff << 8); // clear the previous set bits
    for(int bitPosition = 7; bitPosition >= 0; bitPosition--) {
        andResult = humidity & (1 << bitPosition);
        bitValue = (andResult) ? 1 : 0;
        *field |= (bitValue << (bitPosition + 8));
    }
}

uint32_t get_humidity(uint32_t field) {
    uint32_t intHumidityValue = 0, andResult = 0, bitValue = 0;
    for(int bitPosition = 15; bitPosition >= 8; bitPosition--) {
        andResult = field & (1 << bitPosition);
        bitValue = (andResult) ? 1 : 0;
        intHumidityValue |= (bitValue << (bitPosition - 8));
    }
    return intHumidityValue;
}
