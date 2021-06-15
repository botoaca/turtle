#include "include/Parser.h"
#include "external/tinyexpr/tinyexpr.h"
#include <iostream>
#include <vector>

Parser::Parser(std::vector<std::string> tokens) {
    _tokens = tokens;
};

void Parser::parse() {
    unsigned it = 0;
    while (it < _tokens.size()) {
        // Output Function
        if (!((it + 1) >= _tokens.size())) {
            if (_tokens[it] + " " + _tokens[it + 1].substr(0, 3) == "OUT STR") {
                std::cout << _tokens[it + 1].substr(4) << "\n";
                it += 2;
            }

            if (_tokens[it] + " " + _tokens[it + 1].substr(0, 3) == "OUT NUM") {
                std::cout << _tokens[it + 1].substr(4) << "\n";
                it += 2;
            }

            if (_tokens[it] + " " + _tokens[it + 1].substr(0, 3) == "OUT EXP") {
                char* exp = (char*) _tokens[it + 1].substr(4).c_str();
                std::cout << te_interp(exp, 0) << "\n";
                it += 2;
            }
        }
    }
}