#include "include/Util.h"
#include <iostream>
#include <vector>
#include <unordered_map>
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

std::string util_truncate_string(std::string s) {
    if (s[0] && s[s.size() - 1]) {
        s.erase(0, 1);
        s.erase(s.size() - 1);
    }
    return s;
}

void util_visualize_tokens(std::vector<std::string> v) {
    std::cout << "tokens = { ";
    for (std::string i : v) {
        std::cout << i << ", ";
    }
    std::cout << "}\n";
}

void util_visualize_symbols(std::unordered_map<std::string, std::string> um) {
    std::cout << "symbols = { ";
    for (auto const &pair : um) {
        std::cout << " { " << pair.first << " : " << pair.second << " }, "; 
    }
    std::cout << "}\n";
}