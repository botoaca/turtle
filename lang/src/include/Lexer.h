#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>

class Lexer {
    std::string _fileContents;
    
    public:
        Lexer(std::string);
        std::vector<std::string> lex();
};

#endif // LEXER_H