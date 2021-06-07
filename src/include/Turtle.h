#ifndef TURTLE_H
#define TURTLE_H

#include <iostream>
#include <string>
#include <fstream>

class Turtle {
    std::string _path;

    public:
        Turtle(std::string);
        void run();
};

#endif // TURTLE_H