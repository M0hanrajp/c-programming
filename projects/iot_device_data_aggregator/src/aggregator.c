#include "aggregator.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// program constants
#define MAX_CHARS 34

static uint64_t timestamp = 0;
static int      validReadingCount = 0;
static int      errorReadingCount = 0;
static float    maxTemperature = 0;
static float    minTemperature = 0;
static float    sumTemperature = 0;
static float    maxHumidity = 0;
static float    minHumidity = 0;
static float    sumHumidity = 0;

void sensorDataAggregator(const char *file) {
    FILE *pFile = pFile = fopen(file, "r");

    if(pFile == NULL)
        printf("File does not exist !\n");

    char str[MAX_CHARS];
    while ((fgets(str, MAX_CHARS, pFile)) != NULL) {
        // call the string processor here
        parseSensorData(str);
    }
    fclose(pFile);
    writeSensorData("data/report.txt");
}

void parseSensorData(const char *data) {
    float    rTemperature = 0;
    float    rHumidity = 0;
    int      readingCount = 0;
    static  bool isFirstReading = true;

    readingCount = sscanf(data, "%lu,%f,%f",
                   &timestamp, &rTemperature, &rHumidity);

    // TODO: report invalid reading timestamp to report.txt
    if(readingCount != 3)
        errorReadingCount++;
    else
        validReadingCount++;

    // caluclate the total for each reading
    sumTemperature += rTemperature * 1;
    sumHumidity += rHumidity * 1;

    // calculate max, min for each readings
    if(isFirstReading) {
        maxTemperature = rTemperature * 1;
        minTemperature = rTemperature * 1;
        maxHumidity = rHumidity * 1;
        minHumidity = rHumidity * 1;
        isFirstReading = false;
    } else {
        if(rTemperature && rHumidity) {
            maxTemperature = (rTemperature > maxTemperature ?
                              rTemperature * 1 : maxTemperature);
            minTemperature = (rTemperature < minTemperature ?
                              rTemperature * 1 : minTemperature);

            maxHumidity = (rHumidity > maxHumidity ?
                           rHumidity * 1 : maxHumidity);
            minHumidity = (rHumidity < minHumidity ?
                           rHumidity * 1 : minHumidity);
        }
    }
}

void writeSensorData(const char *file) {
    FILE *pFile = fopen(file, "w");

    if(pFile == NULL)
        printf("File creation failed !\n");

    fprintf(pFile, "--- Sensor Data Summary ---\n"
                   "Data Source: sensor_log.csv\n\n");

    fprintf(pFile, "Readings Processed: %d\n"
                   "Valid Readings: %d\n"
                   "Error Lines: %d\n\n", validReadingCount + errorReadingCount,
                                          validReadingCount,
                                          errorReadingCount);

    fprintf(pFile, "--- Temperature (°C) ---\n"
                   "Min: %.3f\n"
                   "Max: %.3f\n"
                   "Average: %.3f\n\n", minTemperature,
                                        maxTemperature,
                                        sumTemperature / validReadingCount);

    fprintf(pFile, "--- Humidity (%%) ---\n"
                   "Min: %.3f\n"
                   "Max: %.3f\n"
                   "Average: %.3f\n" ,  minHumidity,
                                        maxHumidity,
                                        sumHumidity / validReadingCount);
    fclose(pFile);
}
