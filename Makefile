# Compiler and flags
CC = g++
CFLAGS = -Wall
LIBS = -lmingw32 -lfreeglut -lglew32 -lopengl32 -lglu32

# Find all .c files and corresponding .exe files
SOURCES = $(wildcard *_lab.c)
EXES = $(SOURCES:.c=.exe)

# Default target: build all executables
all: $(EXES)

# Rule to build each executable
%.exe: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

# Clean up generated files (cross-platform)
clean:
	del /q *.exe 2>nul || true
