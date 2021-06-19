#include "include/Parser.h"
#include "include/Util.h"
#include "external/tinyexpr/tinyexpr.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

Parser::Parser(std::vector<std::string> tokens) {
    _tokens = tokens;
};

void Parser::parse() {
    unsigned it = 0;
    while (it < _tokens.size()) {            
        // if (!((it + 2) >= _tokens.size())) {
            // Output String
            if (_tokens[it] + " " + _tokens[it + 1].substr(0, 3) == "OUT STR") {
                std::string str = _tokens[it + 1].substr(4);
                if (str[0] && str[str.size() - 1]) {
                    str.erase(0, 1);
                    str.erase(str.size() - 1);
                }

                std::cout << str << "\n";
                it += 2;
            }

            //  Output Number
            if (_tokens[it] + " " + _tokens[it + 1].substr(0, 3) == "OUT NUM") {
                std::cout << _tokens[it + 1].substr(4) << "\n";
                it += 2;
            }

            // Output Mathematical Expression
            if (_tokens[it] + " " + _tokens[it + 1].substr(0, 3) == "OUT EXP") {
                char* exp = (char*) _tokens[it + 1].substr(4).c_str();
                std::cout << te_interp(exp, 0) << "\n";
                it += 2;
            }

            // To Binary
            if (_tokens[it] + " " + _tokens[it + 1] + " " + _tokens[it + 2].substr(0, 3) == "OUT TO_BINARY STR") {
                std::string str = _tokens[it + 2].substr(4);
                if (str[0] && str[str.size() - 1]) {
                    str.erase(0, 1);
                    str.erase(str.size() - 1);
                }

                std::cout << util_tobinary(str) << "\n";
                it += 3;
            }

            // Parenthese Encode
            if (_tokens[it] + " " + _tokens[it + 1] + " " + _tokens[it + 2].substr(0, 3) == "OUT PARENTHESE_ENCODE STR") {
                std::string str = _tokens[it + 2].substr(4);
                if (str[0] && str[str.size() - 1]) {
                    str.erase(0, 1);
                    str.erase(str.size() - 1);
                }
                std::transform(str.begin(), str.end(), str.begin(), ::toupper);

                std::cout << util_parenthese_encode(str) << "\n";
                it += 3;
            }

            // Parenthese Decode
            if (_tokens[it] + " " + _tokens[it + 1] + " " + _tokens[it + 2].substr(0, 3) == "OUT PARENTHESE_DECODE STR") {
                std::string str = _tokens[it + 2].substr(4);
                if (str[0] && str[str.size() - 1]) {
                    str.erase(0, 1);
                    str.erase(str.size() - 1);
                }
                std::transform(str.begin(), str.end(), str.begin(), ::toupper);

                std::cout << util_parenthese_decode(str) << "\n";
                it += 3;
            }
        // }
    }
}