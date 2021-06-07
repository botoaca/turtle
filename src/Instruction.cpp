#include "include/Instruction.h"
#include <iostream>
#include <string>

Instruction::Instruction() = default;

void Instruction::calculate(std::string line) {
    int firstOperand = line[7] - '0';
    int secondOperand = line[11] - '0';
    switch (line[9]) {
        case '+':
            std::cout << firstOperand + secondOperand;
            break;
        case '-':
            std::cout << firstOperand - secondOperand;
            break;
        case '*':
            std::cout << firstOperand * secondOperand;
            break;
        case '/':
            std::cout << firstOperand / secondOperand;
            break;
        case '%':
            std::cout << firstOperand % secondOperand;
            break;
        default:
            std::cout << "Error.";
            break;
    }
    std::cout << std::endl;
}

void Instruction::input(std::string line, int argSize) {
    std::string input;
    std::cin >> input;
    for (int i = 0; i < argSize; i++) {
        std::cout << input[i];
    }
    std::cout << std::endl;
}

void Instruction::output(std::string line, int argSize, int lineCount) {
    if (line[6 + argSize + 1] != '"') {
            std::cout << "Error: Your argument size, " << argSize << ", on line " << lineCount << " is too small or too big.";
            return;
    }
    for (int i = 0; i < argSize; i++) {
        std::cout << line[7 + i];
    }
    std::cout << std::endl;
}