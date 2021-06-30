#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>
#include <unordered_map>

class Parser {
    std::vector<std::string> _tokens;
    std::unordered_map<std::string, std::string> _symbols;
    
    public:
        Parser(std::vector<std::string>);
        void parse();
        void varAssign(std::string, std::string);
        std::string varGet(std::string);
};

#endif // PARSER_H