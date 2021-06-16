#include "include/Lexer.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define NEW_LINE "\n"
#define D_QUOTE "\""
#define OUT "OUT"
#define TO_BINARY "TO_BINARY"

Lexer::Lexer(std::string fileContents) {
    _fileContents = fileContents + '\n';
};

std::vector<std::string> Lexer::lex() {
    const std::string digits[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
    const std::string operators[8] = { "+", "-", "*", "/", "%", "^", "(", ")" };

    std::vector<std::string> tokens;
    std::string token;
    
    std::string str;
    bool strState = false;

    std::string exp;
    bool expState = false;

    for (unsigned i = 0; i <= _fileContents.length(); i++) {
        token.push_back(_fileContents[i]);
        std::transform(token.begin(), token.end(), token.begin(), ::toupper);

        // SPACE
        if (token == " " && !strState)
            token.clear();

        // NEW LINE
        if (token == NEW_LINE) {
            if (!exp.empty() && expState) {
                tokens.push_back("EXP:" + exp);
                exp.clear();
            }
            else if (!exp.empty() && !expState) {
                tokens.push_back("NUM:" + exp);
                exp.clear();
            }
            token.clear();
        }

        // OUT
        if (token == OUT) {
            tokens.push_back(token);
            token.clear();
        }

        // TO_BINARY
        if (token == TO_BINARY) {
            tokens.push_back(token);
            token.clear();
        }

        // NUMBER
        for (unsigned i = 0; i <= sizeof(digits)/sizeof(digits[0]); i++) {
            if (token == digits[i]) {
                exp += token;
                token.clear();
            }
        }

        // OPERATORS
        for (unsigned i = 0; i <= sizeof(operators)/sizeof(operators[0]); i++) {
            if (token == operators[i]) {
                expState = true;
                exp += token;
                token.clear();
            }
        }

        // DOUBLE QUOTE
        if (token == D_QUOTE) {
            if (!strState) strState = true;
            else if (strState) {
                tokens.push_back("STR:" + str + D_QUOTE);
                str.clear();
                strState = false;
                token.clear();
            }
        }

        if (strState) {
            str += _fileContents[i];
            token.clear();
        }
    }

    // DEBUG: DISPLAY TOKENS
    //
    // std::cout << "tokens = { ";
    // for (std::string i : tokens) {
    //     std::cout << i << ", ";
    // }
    // std::cout << "}\n";

    return tokens;
}