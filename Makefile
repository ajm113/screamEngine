.SILENT:

# Compile configureation.
CC=g++
COMPILE_OPTIONS= -Wall -Wextra -std=c++11

# Project specific configuration.
SRC_DIR=neo/engine/
BUILD_DIR=build/
EXECUTABLE=scream

# Our cpp files we wish to build.
BUILD_OBJS=$(SRC_DIR)scream.cpp


all: build

.PHONY: build

build:
	mkdir -p $(BUILD_DIR)
	$(CC) $(BUILD_OBJS) $(COMPILE_OPTIONS) -o $(BUILD_DIR)$(EXECUTABLE)

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)
