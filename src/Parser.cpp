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
        return _symbols.at(varName).substr(4);
    else
        return "Undefined variable.";
}

void Parser::parse() {
    bool condition = true;
    unsigned it = 0;
    while (it < _tokens.size()) {
        //////////////////////////////////////////////////
        //      1       TOKEN       INSTRUCTIONS        //
        //////////////////////////////////////////////////
        if (it < _tokens.size()) {
            // End If
            if (_tokens.at(it) == "ENDIF") {
                condition = true;
                it++;
                continue;
            }
            
            // Clear Screen
            if (_tokens.at(it) == "CLEAR" && condition) {
                util_clearscreen();
                it++;
                continue;
            }
        }

        //////////////////////////////////////////////////
        //      1       TOKEN       INSTRUCTIONS        //
        //////////////////////////////////////////////////
        if (it + 1 < _tokens.size()) {
            // Output String
            if (_tokens.at(it) + " " + _tokens.at(it + 1).substr(0, 3) == "OUT STR" && condition) {
                std::string str = util_truncate_string(_tokens.at(it + 1).substr(4));
                std::cout << str << "\n";
                it += 2;
                continue;
            }

            //  Output Number
            if (_tokens.at(it) + " " + _tokens.at(it + 1).substr(0, 3) == "OUT NUM" && condition) {
                std::cout << _tokens.at(it + 1).substr(4) << "\n";
                it += 2;
                continue;
            }

            // Output Mathematical Expression
            if (_tokens.at(it) + " " + _tokens.at(it + 1).substr(0, 3) == "OUT EXP" && condition) {
                char* exp = (char*) _tokens.at(it + 1).substr(4).c_str();
                std::cout << te_interp(exp, 0) << "\n";
                it += 2;
                continue;
            }

            // Output Variable
            if (_tokens.at(it) + " " + _tokens.at(it + 1).substr(0, 3) == "OUT VAR" && condition) {
                std::cout << varGet(_tokens.at(it + 1).substr(4)) << "\n";
                it += 2;
                continue;
            }
        }

        //////////////////////////////////////////////////
        //      3       TOKEN       INSTRUCTIONS        //
        //////////////////////////////////////////////////
        if (it + 2 < _tokens.size()) {
            // Input
            if (_tokens.at(it) + " " + _tokens.at(it + 1).substr(0, 3) + " " + _tokens.at(it + 2).substr(0, 3) == "IN STR VAR" && condition) {
                std::string in;
                std::cout << util_truncate_string(_tokens.at(it + 1).substr(4)) << "\n";

                std::cin.ignore();
                std::getline(std::cin, in);
                _symbols[_tokens.at(it + 2).substr(4)] = "STR:\"" + in + "\"";

                it  += 3;
                continue;
            }

            // To Binary
            if (_tokens.at(it) + " " + _tokens.at(it + 1) + " " + _tokens.at(it + 2).substr(0, 3) == "OUT TO_BINARY STR" && condition) {
                std::string str = util_truncate_string(_tokens.at(it + 2).substr(4));
                std::cout << util_tobinary(str) << "\n";
                it += 3;
                continue;
            }

            // Parenthese Encode
            if (_tokens.at(it) + " " + _tokens.at(it + 1) + " " + _tokens.at(it + 2).substr(0, 3) == "OUT PARENTHESE_ENCODE STR" && condition) {
                std::string str = util_truncate_string(_tokens.at(it + 2).substr(4));
                std::transform(str.begin(), str.end(), str.begin(), ::toupper);
                std::cout << util_parenthese_encode(str) << "\n";
                it += 3;
                continue;
            }

            // Parenthese Decode
            if (_tokens.at(it) + " " + _tokens.at(it + 1) + " " + _tokens.at(it + 2).substr(0, 3) == "OUT PARENTHESE_DECODE STR" && condition) {
                std::string str = util_truncate_string(_tokens.at(it + 2).substr(4));
                std::transform(str.begin(), str.end(), str.begin(), ::toupper);
                std::cout << util_parenthese_decode(str) << "\n";
                it += 3;
                continue;
            }

            // String Variable
            if (_tokens.at(it).substr(0, 3) + " " + _tokens.at(it + 1) + " " + _tokens.at(it + 2).substr(0, 3) == "VAR EQUALS STR" && condition) {
                varAssign(_tokens.at(it), _tokens.at(it + 2));
                it += 3;
                continue;
            }

            // Num Variable
            if (_tokens.at(it).substr(0, 3) + " " + _tokens.at(it + 1) + " " + _tokens.at(it + 2).substr(0, 3) == "VAR EQUALS NUM" && condition) {
                varAssign(_tokens.at(it), _tokens.at(it + 2));
                it += 3;
                continue;
            }

            // Expression Variable
            if (_tokens.at(it).substr(0, 3) + " " + _tokens.at(it + 1) + " " + _tokens.at(it + 2).substr(0, 3) == "VAR EQUALS EXP" && condition) {
                char* exp = (char*) _tokens.at(it + 2).substr(4).c_str();
                std::string evaluatedExp = std::to_string(te_interp(exp, 0));
                varAssign(_tokens.at(it), "NUM:" + evaluatedExp);
                it += 3;
                continue;
            }

            // Variable = Variable
            if (_tokens.at(it).substr(0, 3) + " " + _tokens.at(it + 1) + " " + _tokens.at(it + 2).substr(0, 3) == "VAR EQUALS VAR" && condition) {
                varAssign(_tokens.at(it), "STR:" + varGet(_tokens.at(it + 2).substr(4)));
                it += 3;
                continue;
            }
        }

        //////////////////////////////////////////////////
        //      5       TOKEN       INSTRUCTIONS        //
        //////////////////////////////////////////////////
        if (it + 4 < _tokens.size()) {
            // If Str is Str
            if (_tokens.at(it) + " " + _tokens.at(it + 1).substr(0, 3) + " " + _tokens.at(it +2) + " " +
                _tokens.at(it + 3).substr(0, 3) + " " + _tokens.at(it + 4) == "IF STR IS STR THEN") {
                    if (!(_tokens.at(it + 1).substr(4) == _tokens.at(it + 3).substr(4)))
                        condition = false;
                    it += 5;
                    continue;
            }

            // If Num is Num
            if (_tokens.at(it) + " " + _tokens.at(it + 1).substr(0, 3) + " " + _tokens.at(it + 2) + " " +
                _tokens.at(it + 3).substr(0, 3) + " " + _tokens.at(it + 4)== "IF NUM IS NUM THEN") {
                    if (!(_tokens.at(it + 1).substr(4) == _tokens.at(it + 3).substr(4)))
                        condition = false;
                    it += 5;
                    continue;
            }   
        }
    }
    
    // DEBUG: DISPLAY SYMBOLS
    // util_visualize_symbols(_symbols);
}