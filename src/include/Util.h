#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <bitset>
#include <vector>
#include <unordered_map>
#include <string>

void util_clearscreen();

std::string util_tobinary(std::string);
std::string util_parenthese_encode(std::string);
std::string util_parenthese_decode(std::string);

std::string util_truncate_string(std::string);
void util_visualize_tokens(std::vector<std::string>);
void util_visualize_symbols(std::unordered_map<std::string, std::string>);

#endif // UTIL_H