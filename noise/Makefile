# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11

# Source file
SRC = perlin-noise.cpp

# Executable name
EXEC = noise

# Default target
all: $(EXEC)

# Compile target
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

# Clean target
clean:
	rm -f $(EXEC)
