#include "include/Turtle.h"

int main() {
    std::string path;
    std::cout << "************************\n";
    std::cout << "INFO  : Input your file:\n";
    std::cout << "INPUT : "; std::cin >> path;
    std::cout << "************************\n";

    Turtle t(path);
    t.run();
    return 0;
}