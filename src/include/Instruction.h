#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>

class Instruction {
    public:
        Instruction();
        void calculate(std::string);
        void input(std::string, int);
        void output(std::string, int, int);
};

#endif // INSTRUCTION_H