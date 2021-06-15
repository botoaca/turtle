#include "include/Lexer.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


#define NEW_LINE "\n"
#define D_QUOTE "\""
#define OUT "OUT"

Lexer::Lexer(std::string fileContents) {
    _fileContents = fileContents + '\n';
};

std::vector<std::string> Lexer::lex() {
    const std::string digits[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
    const std::string operators[7] = { "+", "-", "*", "/", "%", "(", ")" };

    std::vector<std::string> tokens;
    std::string token;
    bool state = false;

    std::string str;
    std::string exp;
    bool isExpression = false;

    for (unsigned i = 0; i <= _fileContents.length(); i++) {
        token.push_back(_fileContents[i]);
        std::transform(token.begin(), token.end(), token.begin(), ::toupper);

        // SPACE
        if (token == " " && !state)
            token.clear();

        // NEW LINE
        if (token == NEW_LINE) {
            if (!exp.empty() && isExpression) {
                tokens.push_back("EXP:" + exp);
                exp.clear();
            }
            else if (!exp.empty() && !isExpression) {
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

        // NUMBER
        for (int i = 0; i <= 10; i++) {
            if (token == digits[i]) {
                exp += token;
                token.clear();
            }
        }

        // OPERATORS
        for (int i = 0; i <= 5; i++) {
            if (token == operators[i]) {
                isExpression = true;
                exp += token;
                token.clear();
            }
        }

        // DOUBLE QUOTE
        if (token == D_QUOTE) {
            if (!state) state = true;
            else if (state) {
                tokens.push_back("STR:" + str + D_QUOTE);
                str.clear();
                state = false;
                token.clear();
            }
        }

        if (state) {
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