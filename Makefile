CXX = g++
CXXFLAGS = -Wall

all: build build/output

build:
	mkdir build

build/output: build/main.o build/turtle.o build/instruction.o
	$(CXX) $(CXXFLAGS) $^ -o $@

build/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/turtle.o: src/Turtle.cpp src/include/Turtle.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/instruction.o: src/Instruction.cpp src/include/Instruction.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
