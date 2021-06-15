#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>

class Parser {
    std::vector<std::string> _tokens;
    
    public:
        Parser(std::vector<std::string>);
        void parse();
};

#endif // PARSER_H