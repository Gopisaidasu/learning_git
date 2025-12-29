# Compiler and flags
CC = g++
CFLAGS = -Wall -Wextra 



# Source files
SRC_FILES = calculator.c
TEST_SRC_FILES = test_calculator.cpp
UNITY_SRC_FILES = catch_main.o



# Compile the test runner (testrunner) and link with Unity framework
testrunner: $(TEST_SRC_FILES) $(SRC_FILES) 
	g++ $(CFLAGS) -o testrunner $(TEST_SRC_FILES) $(SRC_FILES) $(UNITY_SRC_FILES)

# Run tests by invoking testrunner
test: testrunner
	./testrunner

# Clean up by removing binaries
clean:
	rm -f calc testrunner

