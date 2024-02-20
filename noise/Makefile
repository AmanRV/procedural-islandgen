# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11

# Source file
SRC = perlin-noise.cpp

# Executable name
EXEC = noise

CFLAGS=-Wall -Wextra -O2 -Wno-unused-parameter -Wno-unused-variable


# Default target
all: $(EXEC)

# Compile target
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

# Clean target
clean:
	rm -f $(EXEC)
