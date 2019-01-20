.SILENT:

# Compile configureation.
CC=g++
COMPILE_OPTIONS= -D_GLIBCXX_USE_CXX11_ABI=0

# Project specific configuration.
SRC_DIR=neo/engine/
BUILD_DIR=build/
EXECUTABLE=scream

# Our cpp files we wish to build.
BUILD_OBJS=$(SRC_DIR)scream.cpp

.PHONY: build

build:
	mkdir -p $(BUILD_DIR)
	$(CC) $(BUILD_OBJS) $(COMPILE_OPTIONS) -o $(BUILD_DIR)$(EXECUTABLE)

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)
