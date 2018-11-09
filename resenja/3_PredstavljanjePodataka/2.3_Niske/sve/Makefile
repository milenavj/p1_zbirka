# Setup basic things
CC=gcc
CFLAGS=-std=c99 -Wall -Wextra
LDFLAGS=-lm

# Generate list of executables [usage: $(subst, pattern, replacement, text)]
EXECUTABLES:= $(subst  .c, , $(wildcard *.c))

# Create 'all' rule
all: $(EXECUTABLES)

%:%.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

# Create 'clean' rule
.PHONY: clean beauty

clean:
	rm -rf *.o *~ $(EXECUTABLES)

beauty:
	indent -fc1 -fca -kr --no-tabs --line-length68 -i2 *.c 