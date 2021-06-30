#include "include/Turtle.h"

int main(int argc, char* argv[]) {
    std::string path;
    
    if (argc == 1) {
        std::cout << "************************\n";
        std::cout << "INFO  : Input your file:\n";
        std::cout << "INPUT : "; std::cin >> path;
        std::cout << "************************\n";
    } else path = argv[1];

    Turtle t(path);
    t.run();
    return 0;
}