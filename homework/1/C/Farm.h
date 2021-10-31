//Farm.h

#ifndef FARM_H_
#define FARM_H_

#include "Cow.h"

#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>

const int maxn = 100 + 5;

class Farm {
private:
    int n, tail;
    Cow *cow;
    double milk;
public:
    Farm(int x) {
        n = x;
        tail = 0;
        cow = new Cow[n + 5];
        milk = 0;
    }
    void addCow(Cow c);
    void supply(std::string name, int sup);
    void startMeal();
    void produceMilk();
    double getMilkProduction();
};

#endif