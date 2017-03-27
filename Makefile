build: main.c
	mkdir bin & $(CC) $? -lncurses -o bin/main
