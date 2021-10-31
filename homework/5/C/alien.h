#pragma once

#include "what.h"
#include <cstring>

class Alien : public WhatCanMotion , public WhatCanSpeak{
private:
    std::string name;
public:
    Alien(std::string x) {
        name = x;
    }
    void speak() {
        std::cout << name << " is speaking" << std::endl;
    }
    void motion() {
        std::cout << name << " is moving" << std::endl;
    }
    void stop() {
        std::cout << name << " stops" << std::endl;
    }
};