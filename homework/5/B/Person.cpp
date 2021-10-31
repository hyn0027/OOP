#include "Person.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

Person::Person(std::string x) {
    name = x;
    chat.clear();
}

void Person::add(std::string x) {
    chat.push_back(x);
}

void Person::output() {
    std::cout << name << std::endl;
    for (int i = chat.size() - 1; i >= 0; i--)
        std::cout << chat[i] << std::endl;
}

bool Person::same(std::string x) {
    return name == x;
}