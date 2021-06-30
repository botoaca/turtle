CXX = g++
CC = gcc
CXXFLAGS = -Wall

all: build build/external build/output

build:
	mkdir build

build/external:
	mkdir "build/external"

build/output: build/main.o build/turtle.o build/lexer.o build/parser.o build/util.o build/external/tinyexpr.o
	$(CXX) $(CXXFLAGS) $^ -o $@

build/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/turtle.o: src/Turtle.cpp src/include/Turtle.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/lexer.o: src/Lexer.cpp src/include/Lexer.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/parser.o: src/Parser.cpp src/include/Parser.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/util.o: src/Util.cpp src/include/Util.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/external/tinyexpr.o: src/external/tinyexpr/tinyexpr.c src/external/tinyexpr/tinyexpr.h
	$(CC) $(CFLAGS) -c $< -o $@