build: main.cpp
	mkdir bin & $(CXX) $? -lncurses -o bin/main
