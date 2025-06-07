#ifndef AGGREGATOR_H
#define AGGREGATOR_H

/**
 * @brief Orchestrates the entire sensor data aggregation process.
 *
 * This function serves as the main controller. It opens the specified input log file,
 * reads it line by line, and passes each line to `parseSensorData` for processing.
 * After the entire file has been read, it calls `writeSensorData` to generate
 * the final summary report. It also handles file-opening errors.
 *
 * @param inputFile A pointer to a constant character string representing the path
 * to the source sensor log file (e.g., "sensor_log.csv").
 *
 */
void sensorDataAggregator(const char *file);
/**
 * @brief Parses a single line of text from the sensor log.
 *
 * This function takes a string containing one line of sensor data and attempts
 * to parse it into its components (timestamp, temperature, humidity). If successful,
 * it updates the shared statistical variables (min, max, total, count). If the
 * line is malformed or contains an error message, it increments an error counter.
 *
 * @param data A pointer to a constant character string containing a single line
 * read from the sensor log file. The expected format is a
 * comma-separated string like "1677650400,20.5,45.2".
 *
 * @note This function directly modifies the program's shared state (e.g., global
 * or static variables for min/max/average calculations). It does not
 * return a value.
 */
void parseSensorData(const char *data);
/**
 * @brief Writes the aggregated sensor statistics to a final report file.
 *
 * This function should be called after all data has been parsed. It reads the
 * final calculated statistics from the shared program state and writes them
 * in a formatted, human-readable summary to the specified output file.
 *
 * @param outputFile A pointer to a constant character string representing the path
 * for the destination report file (e.g., "report.txt"). If this
 * file already exists, its contents will be overwritten.
 *
 * @note This function's output depends entirely on the state of the shared
 * statistical variables that were populated by previous calls to
 * `parseSensorData`.
 */
void writeSensorData(const char *file);

#endif
