#include "include/Util.h"
#include <iostream>
#include <bitset>
#include <string>

void util_clearscreen() {
    #include <stdlib.h>
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

std::string util_tobinary(std::string s) {
    std::string converted;
    for (unsigned i = 0; i < s.size(); i++) {
        converted += std::bitset<8>(s[i]).to_string() + ' ';
    }
    return converted;
}

std::string util_parenthese_encode(std::string s) {
    std::string converted;
    for (unsigned i = 0; i < s.size(); i++)
    {
        unsigned pos = 0;
        if (s[i] >= 65 && s[i] <= 98)
            pos = s[i] - 64;
        
        for (unsigned i = 0; i < pos; i++) {
            converted += ")";
        }
        converted += "(";
    }
    return converted;
}

std::string util_parenthese_decode(std::string s) {
    std::string converted;
    int parenCount = 0;
    for (unsigned i = 0; i < s.size(); i++) {
        if (s[i] == ')') parenCount++;
        if (s[i] == '(') {
            converted += (char) parenCount + 64;
            parenCount = 0;
        }
    }
    return converted;
}