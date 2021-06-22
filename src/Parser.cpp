#include "include/Parser.h"
#include "include/Util.h"
#include "external/tinyexpr/tinyexpr.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

Parser::Parser(std::vector<std::string> tokens) {
    _tokens = tokens;
};

void Parser::varAssign(std::string varName, std::string varValue) {
    _symbols[varName.substr(4)] = varValue;
}

std::string Parser::varGet(std::string varName) {
    if (_symbols.count(varName))
        return _symbols[varName].substr(4);
    else
        return "Undefined variable.";
}

void Parser::parse() {
    unsigned it = 0;
    while (it < _tokens.size()) {
        // Clear Screen
        if (_tokens[it] == "CLEAR") {
            util_clearscreen();
            it++;
            continue;
        }

        // Output String
        if (_tokens[it] + " " + _tokens[it + 1].substr(0, 3) == "OUT STR") {
            std::string str = util_truncate_string(_tokens[it + 1].substr(4));
            std::cout << str << "\n";
            it += 2;
            continue;
        }

        //  Output Number
        if (_tokens[it] + " " + _tokens[it + 1].substr(0, 3) == "OUT NUM") {
            std::cout << _tokens[it + 1].substr(4) << "\n";
            it += 2;
            continue;
        }

        // Output Mathematical Expression
        if (_tokens[it] + " " + _tokens[it + 1].substr(0, 3) == "OUT EXP") {
            char* exp = (char*) _tokens[it + 1].substr(4).c_str();
            std::cout << te_interp(exp, 0) << "\n";
            it += 2;
            continue;
        }

        // Output Variable
        if (_tokens[it] + " " + _tokens[it + 1].substr(0, 3) == "OUT VAR") {
            std::cout << varGet(_tokens[it + 1].substr(4)) << "\n";
            it += 2;
            continue;
        }

        if (_tokens[it] + " " + _tokens[it + 1].substr(0, 3) + " " + _tokens[it + 2].substr(0, 3) == "IN STR VAR") {
            std::string in;
            std::cout << util_truncate_string(_tokens[it + 1].substr(4)) << "\n";

            std::cin.ignore();
            std::getline(std::cin, in);
            _symbols[_tokens[it + 2].substr(4)] = "STR:\"" + in + "\"";

            it  += 3;
            continue;
        }

        // To Binary
        if (_tokens[it] + " " + _tokens[it + 1] + " " + _tokens[it + 2].substr(0, 3) == "OUT TO_BINARY STR") {
            std::string str = util_truncate_string(_tokens[it + 2].substr(4));
            std::cout << util_tobinary(str) << "\n";
            it += 3;
            continue;
        }

        // Parenthese Encode
        if (_tokens[it] + " " + _tokens[it + 1] + " " + _tokens[it + 2].substr(0, 3) == "OUT PARENTHESE_ENCODE STR") {
            std::string str = util_truncate_string(_tokens[it + 2].substr(4));
            std::transform(str.begin(), str.end(), str.begin(), ::toupper);
            std::cout << util_parenthese_encode(str) << "\n";
            it += 3;
            continue;
        }

        // Parenthese Decode
        if (_tokens[it] + " " + _tokens[it + 1] + " " + _tokens[it + 2].substr(0, 3) == "OUT PARENTHESE_DECODE STR") {
            std::string str = util_truncate_string(_tokens[it + 2].substr(4));
            std::transform(str.begin(), str.end(), str.begin(), ::toupper);
            std::cout << util_parenthese_decode(str) << "\n";
            it += 3;
            continue;
        }

        // String Variable
        if (_tokens[it].substr(0, 3) + " " + _tokens[it + 1] + " " + _tokens[it + 2].substr(0, 3) == "VAR EQUALS STR") {
            varAssign(_tokens[it], _tokens[it + 2]);
            it += 3;
            continue;
        }

        // Num Variable
        if (_tokens[it].substr(0, 3) + " " + _tokens[it + 1] + " " + _tokens[it + 2].substr(0, 3) == "VAR EQUALS NUM") {
            varAssign(_tokens[it], _tokens[it + 2]);
            it += 3;
            continue;
        }

        // Expression Variable
        if (_tokens[it].substr(0, 3) + " " + _tokens[it + 1] + " " + _tokens[it + 2].substr(0, 3) == "VAR EQUALS EXP") {
            char* exp = (char*) _tokens[it + 2].substr(4).c_str();
            std::string evaluatedExp = std::to_string(te_interp(exp, 0));
            varAssign(_tokens[it], "NUM:" + evaluatedExp);
            it += 3;
            continue;
        }

        // Variable = Variable
        if (_tokens[it].substr(0, 3) + " " + _tokens[it + 1] + " " + _tokens[it + 2].substr(0, 3) == "VAR EQUALS VAR") {
            varAssign(_tokens[it], "VAL:" + varGet(_tokens[it + 2].substr(4)));
            it += 3;
            continue;
        }
    }
    
    // DEBUG: DISPLAY SYMBOLS
    // util_visualize_symbols(_symbols);
}