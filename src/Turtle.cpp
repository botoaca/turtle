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

    Lexer lexer(contents.str() + '\n');
    std::vector<std::string> tokens = lexer.lex();

    Parser parser(tokens);
    parser.parse();
}