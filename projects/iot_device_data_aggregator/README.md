### **Mini-Project: IoT Device Data Aggregator**

**Domain:** IoT / Operating System

---

### **1. The Real-World Scenario**

Imagine you have an IoT weather station deployed in the field. This device measures temperature and humidity every minute and writes the raw data to a log file on its internal storage. The device has limited network bandwidth, so it can't send every single reading to the cloud.

Your task is to write a C program that runs on the device periodically (e.g., once an hour). This program will read the raw, minute-by-minute data log, calculate summary statistics (like min, max, average), and write a single, consolidated report file. This small report file is what will be sent over the network, saving significant bandwidth.

This is a fundamental task in both IoT (data pre-processing) and Operating Systems (log file rotation and summarization).

### **2. Project Objective**

To create a C program named `aggregator` that reads a raw sensor data file (`sensor_log.csv`), processes the data, and writes a summary report (`report.txt`).

### **3. Core Tasks & File Operations You'll Learn**

#### **Task 0: Setup (The "Fake" IoT Device)**

You don't have a real IoT device, so you'll simulate it.

1.  Create a text file named `sensor_log.csv`.
2.  Populate it with some sample data. Each line should represent a reading in the format: `timestamp,temperature,humidity`.

**Example `sensor_log.csv`:**
```
1677650400,20.5,45.2
1677650460,20.6,45.3
1677650520,21.0,45.1
1677650580,20.9,46.0
1677650640,ERROR,SENSOR_FAILURE
1677650700,21.5,46.5
1677650760,21.7,46.3
1677650820,21.4,47.0
```
*Note the intentional `ERROR` line. Real-world data is rarely perfect!*

#### **Task 1: Reading the Raw Data**

* **Goal:** Open and read `sensor_log.csv` line by line.
* **C Concepts:**
    * `FILE *fopen(const char *filename, const char *mode)`: You'll use this to open `sensor_log.csv` in **read mode** (`"r"`).
    * **Error Handling:** What if the file doesn't exist? Your program must check if `fopen()` returned `NULL` and print a user-friendly error.
    * `char *fgets(char *str, int n, FILE *stream)`: This is the perfect function to read a file one line at a time.
    * `int fclose(FILE *stream)`: Always close the file when you're done.

#### **Task 2: Parsing and Processing**

* **Goal:** For each line read, parse the data. If it's a valid line, update your statistics. If it's an error, count it.
* **C Concepts:**
    * **String Parsing:** Use `sscanf()` or `strtok()` to extract the timestamp, temperature, and humidity from the line you read with `fgets()`. `sscanf()` is often safer and easier for fixed formats.
    * **Data Validation:** The return value of `sscanf()` tells you how many items were successfully parsed. If it's less than 3, you know it's a malformed line (like our `ERROR` line).
    * **keep track of:**
        * `min_temp`, `max_temp`, `total_temp`
        * `min_humidity`, `max_humidity`, `total_humidity`
        * `valid_reading_count`, `error_line_count`
    * **Calculation:** After reading all lines, calculate the average temperature and humidity. `avg_temp = total_temp / valid_reading_count`.

#### **Task 3: Writing the Summary Report**

* **Goal:** Create a new file, `report.txt`, and write your calculated summary into it in a clean, human-readable format.
* **C Concepts:**
    * `FILE *fopen(const char *filename, const char *mode)`: This time, you'll open `report.txt` in **write mode** (`"w"`). This mode creates the file if it doesn't exist or overwrites it if it does.
    * `int fprintf(FILE *stream, const char *format, ...)`: This works just like `printf`, but it writes to a file instead of the console. Use it to format your report nicely.
    * `fclose()`: Don't forget to close your output file!

**Example `report.txt` output:**
```
--- Sensor Data Summary ---
Data Source: sensor_log.csv

Readings Processed: 8
Valid Readings: 7
Error Lines: 1

--- Temperature (°C) ---
Min: 20.50
Max: 21.70
Average: 21.09

--- Humidity (%) ---
Min: 45.10
Max: 47.00
Average: 46.06
```
