#include "include/Turtle.h"
#include "include/Lexer.h"
#include "include/Parser.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

Turtle::Turtle(std::string path) {
    _path = path;
}

void Turtle::run() {
    std::ifstream input(_path);
    std::stringstream contents;
    contents << input.rdbuf();

    Lexer lexer(contents.str());
    std::vector<std::string> tokens = lexer.lex();

    Parser parser(tokens);
    parser.parse();


    // int lineCount = 0;
    // int argSize;

    // while (std::getline(input, line)) { // Executes instructions for each line
    //     lineCount++;
    //     if (line[0] != '#')
    //         argSize = line[0] - '0';

    //     // CALC function
    //     if (line[2] == 'C' && line[3] == 'A' && line[4] == 'L' && line[5] == 'C')
    //         i.calculate(line);

    //     // INPUT function
    //     if (line[2] == 'I' && line[3] == 'N')
    //         i.input(line, argSize);

    //     // OUTPUT function
    //     if (line[2] == 'O' && line[3] == 'U' && line[4] == 'T' && line[6] == '"')
    //         i.output(line, argSize, lineCount);
    // }
}