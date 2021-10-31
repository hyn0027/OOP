#include <iostream>
#include "Parser.h"

int main(int argc, char *argv[]) {
    Parser parser = Parser();

    parser.add_argument("--one", 1, "First number");
    parser.add_argument("--two", 2, "Next number");
    parser.add_argument("--three", 3, "Third number");

    parser.init(argc, argv);

    int a = parser.get_argument("one");
    int b = parser.get_argument("two");
    int c = parser.get_argument("three");

    std::cout << a + b * c << std::endl;

    return 0;
}