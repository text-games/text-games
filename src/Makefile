TARGET = ../bin/main
LIBS = -lm -lncurses
CC = gcc
CFLAGS = -g -Wall

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, ../obj/%.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

../obj/%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f ../obj/*.o
	-rm -f $(TARGET)
