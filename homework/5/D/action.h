//action.h

#pragma once

#include "animal.h"
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

void action(Animal* animal, std::vector<Dog> & dogzone, std::vector<Bird> & birdzone) {
    Dog* pdog = dynamic_cast<Dog*>(animal);
    Bird* pbird = dynamic_cast<Bird*>(animal);
    if (pdog != nullptr) {
        dogzone.push_back(std::move(*pdog));
        pdog = nullptr;
    }
    else {
        birdzone.push_back(std::move(*pbird));
        pbird = nullptr;
    }
}