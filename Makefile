# Compiler
CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude

# Directories
SRC_DIR = src
TEST_DIR = test
INCLUDE_DIR = include

# Source files
SRC_FILES = $(SRC_DIR)/main.cpp \
            $(SRC_DIR)/gameEngine/driver.cpp \
            $(SRC_DIR)/environment/floor.cpp \
            $(SRC_DIR)/characters/npc.cpp

# Test file
TEST_FILE = $(TEST_DIR)/TestDriver.cpp

# Output binary
TEST_BINARY = test_driver

# Default target to compile and run tests
all: $(TEST_BINARY)

# Compile the test executable
$(TEST_BINARY): $(SRC_FILES) $(TEST_FILE)
	$(CXX) $(CXXFLAGS) -o $@ $(SRC_FILES) $(TEST_FILE)

# Clean up object files and binary
clean:
	rm -f $(TEST_BINARY)
