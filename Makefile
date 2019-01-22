
# Compile configureation.
CC=g++
COMPILE_OPTIONS= -Wall -Wextra -std=c++11
COMPILE_LINK= -lX11 -lGL -lpthread

# Project specific configuration.
SRC_DIR=neo/engine/
BUILD_DIR=build/
EXECUTABLE=scream

# Our cpp files we wish to build.
BUILD_OBJS=$(SRC_DIR)scream.cpp \
	   $(SRC_DIR)logger.cpp \
	   $(SRC_DIR)sys/x11/window.cpp

BUILD_OBJS_EXECUTABLE=$(BUILD_OBJS) $(SRC_DIR)main.cpp

# Test Compile configuration
TEST_DIR=test/
TEST_COMPILE_INCLUDES= -Ineo/lest/include/lest
TEST_COMPILE_OPTIONS= -Wall -Wextra -std=c++11
TEST_BUILD_DIR=$(BUILD_DIR)test/
TEST_BUILD_OBJS=$(TEST_DIR)scream.cpp

all: build

.PHONY: build

build:
	mkdir -p $(BUILD_DIR)
	$(CC) $(BUILD_OBJS_EXECUTABLE) $(COMPILE_OPTIONS) $(COMPILE_LINK) -o $(BUILD_DIR)$(EXECUTABLE)

.PHONY: test

test:
	mkdir -p $(TEST_BUILD_DIR)
	$(CC) $(TEST_BUILD_OBJS) $(BUILD_OBJS) $(TEST_COMPILE_OPTIONS) $(COMPILE_LINK) $(TEST_COMPILE_INCLUDES) -o $(TEST_BUILD_DIR)$(EXECUTABLE)test
	$(TEST_BUILD_DIR)$(EXECUTABLE)test

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)
