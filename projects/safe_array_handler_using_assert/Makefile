# Compiler
CC := gcc

# Compiler flags
CFLAGS := -g -Wall -Wextra -std=c2x

# Directory, Explicit relative path from current dir, i.e. reason for using dot ./src
BUILD_DIR := ./build
SRC_DIR := ./src
LOG_DIR := ./log

# Target executable
TARGET := $(BUILD_DIR)/assert_test_safe_array

# Source files, creates a list of main.c utils.c ..
SRC := $(shell find $(SRC_DIR) -name '*.c')

# Object files, takes SRC list, matches them in src/, and creates main.o utils.o
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))

# Tells make that clean is not a real file target.
.PHONY: build clean run

build: $(TARGET)
	@printf "\e[32m[Build success]\e[0m, binaries are stored in build directory\n"
	
# Build rule for final target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .c to .o
# Based on the dependency list mentioned for object files, it builds .o one by one
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "\e[33m[Object file build success]\e[0m, .o files are stored in build directory\n"

run: $(TARGET)
	@mkdir -p $(LOG_DIR)
	./$(TARGET) | tee $(LOG_DIR)/assert_safe_array.log
	@printf "\n\e[32m[Program exit success!]\e[0mfind logs in log/ directory\n"

# Clean up build files
clean:
	rm -rf $(BUILD_DIR) $(LOG_DIR)

############################
# Notes:
############################
# Anywhere you write $(VAR_NAME), make replaces it with VAR_NAME., similar to ${VAR_NAME}
# $@ The target filename that make is using to build the project.
# $< The first prerequisite (dependency) Usually the source file being compiled
# $^ All prerequisites (dependencies) All source or object files needed
# %.c or %.o > whatever filename base matches, % is a wildcard
#  turn text to some color on the terminal
# echo -e "\e[32mThis is green text!\e[0m"
#  | Color     | Code | Example              |
#  | --------- | ---- | -------------------- |
#  | Black     | `30` | `\e[30mBlack\e[0m`   |
#  | Red       | `31` | `\e[31mRed\e[0m`     |
#  | **Green** | `32` | `\e[32mGreen\e[0m`   |
#  | Yellow    | `33` | `\e[33mYellow\e[0m`  |
#  | Blue      | `34` | `\e[34mBlue\e[0m`    |
#  | Magenta   | `35` | `\e[35mMagenta\e[0m` |
#  | Cyan      | `36` | `\e[36mCyan\e[0m`    |
#  | White     | `37` | `\e[37mWhite\e[0m`   |
