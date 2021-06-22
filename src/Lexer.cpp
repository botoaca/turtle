#include "include/Lexer.h"
#include "include/Util.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define NEW_LINE "\n"
#define D_QUOTE "\""
#define OUT "OUT"
#define IN "IN"
#define TO_BINARY "TO_BINARY"
#define P_ENCODE "PARENTHESE_ENCODE"
#define P_DECODE "PARENTHESE_DECODE"
#define CLEAR_SCREEN "CLEAR"
#define DECLARE "@"
#define EQUALS "="

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

    std::string var;
    bool varStart = false;

    for (unsigned i = 0; i < _fileContents.length(); i++) {
        token.push_back(::toupper(_fileContents[i]));

        // SPACE
        if (token == " " && !strState) {
            token.clear();
            continue;
        }

        // NEW LINE
        if (token == NEW_LINE) {
            if (!exp.empty() && expState) {
                tokens.push_back("EXP:" + exp);
                exp.clear();
            }
            if (!exp.empty() && !expState) {
                tokens.push_back("NUM:" + exp);
                exp.clear();
            }
            if (!var.empty()) {
                tokens.push_back("VAR:" + var);
                var.clear();
                varStart = false;
            }
            token.clear();
            continue;
        }

        // DEC
        if (token == EQUALS && !strState) {
            if (!var.empty()) {
                tokens.push_back("VAR:" + var);
                var.clear();
                varStart = false;
            }
            tokens.push_back("EQUALS");
            token.clear();
            continue;
        }

        if (token == DECLARE && !strState) {
            varStart = true;
            var += token;
            token.clear();
            continue;
        }

        if (varStart) {
            var += token;
            token.clear();
            continue;
        }

        // OUT
        if (token == OUT) {
            tokens.push_back(token);
            token.clear();
            continue;
        }

        if (token == IN) {
            tokens.push_back(token);
            token.clear();
            continue;
        }

        // TO_BINARY
        if (token == TO_BINARY) {
            tokens.push_back(token);
            token.clear();
            continue;
        }

        // PARENTHESE_ENCODE
        if (token == P_ENCODE) {
            tokens.push_back(token);
            token.clear();
            continue;
        }

        // PARENTHESE_DECODE
        if (token == P_DECODE) {
            tokens.push_back(token);
            token.clear();
            continue;
        }

        // CLEAR
        if (token == CLEAR_SCREEN)  {
            tokens.push_back(token);
            token.clear();
            continue;
        }

        // NUMBER
        for (unsigned i = 0; i < sizeof(digits)/sizeof(digits[0]); i++) {
            if (token == digits[i]) {
                exp += token;
                token.clear();
                continue;
            }
        }

        // OPERATORS
        for (unsigned i = 0; i < sizeof(operators)/sizeof(operators[0]); i++) {
            if (token == operators[i]) {
                expState = true;
                exp += token;
                token.clear();
                continue;
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
                continue;
            }
        }

        if (strState) {
            str += _fileContents[i];
            token.clear();
            continue;
        }
    }

    // DEBUG: VISUALIZE TOKENS
    util_visualize_tokens(tokens);

    return tokens;
}