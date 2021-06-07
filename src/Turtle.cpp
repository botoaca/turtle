#include "include/Turtle.h"
#include "include/Instruction.h"
#include <iostream>
#include <string>
#include <fstream>

Turtle::Turtle(std::string path) {
    _path = path;
}

void Turtle::run() {
    Instruction i;

    std::string line;
    std::ifstream input(_path);
    int lineCount = 0;

    while (std::getline(input, line)) { // Executes instructions for each line
        lineCount++;
        int argSize = line[0] - '0';

        // CALC function
        if (line[2] == 'C' && line[3] == 'A' && line[4] == 'L' && line[5] == 'C')
            i.calculate(line);

        // INPUT function
        if (line[2] == 'I' && line[3] == 'N')
            i.input(line, argSize);

        // OUTPUT function
        if (line[2] == 'O' && line[3] == 'U' && line[4] == 'T' && line[6] == '"')
            i.output(line, argSize, lineCount);
    }
}