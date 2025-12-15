# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Paths and source files
UNITY_DIR = unity

# Source files
SRC_FILES = calculator.c
TEST_SRC_FILES = test_calc.cpp
UNITY_SRC_FILES = $(UNITY_DIR)/unity.c

# Targets
all: calc

# Compile the main calculator program
calc: $(SRC_FILES) main.c
	$(CC) $(CFLAGS) -o calc $(SRC_FILES) main.c

# Compile the test runner (testrunner) and link with Unity framework
testrunner: $(TEST_SRC_FILES) $(SRC_FILES) $(UNITY_SRC_FILES)
	g++ $(CFLAGS) -o testrunner $(TEST_SRC_FILES) $(SRC_FILES) $(UNITY_SRC_FILES)

# Run tests by invoking testrunner
test: testrunner
	./testrunner

# Clean up by removing binaries
clean:
	rm -f calc testrunner

