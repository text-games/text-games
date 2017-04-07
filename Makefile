TARGET = bin/main
LIBS = -lm -lncurses
CC = gcc
CFLAGS = -g -Wall

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS := $(patsubst src/%.c, obj/%.o, $(shell find src/ -type f -name '*.c'))
HEADERS := $(shell find src/ -type f -name '*.h')
DIRECTORIES := $(patsubst src/%, obj/%, $(shell find src/ -type d -name '*'))

obj/%.o: src/%.c $(HEADERS) $(DIRECTORIES)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS) $(DIRECTORIES)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f obj/*.o
	-rm -f $(TARGET)
obj/%: src/%
	mkdir -p $@
