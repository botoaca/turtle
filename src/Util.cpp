#include "include/Util.h"
#include <iostream>
#include <bitset>
#include <string>

std::string util_tobinary(std::string s) {
    std::string converted;
    for (unsigned i = 0; i < s.size(); i++) {
        converted += std::bitset<8>(s[i]).to_string() + ' ';
    }
    return converted;
}