//Cow.h
#ifndef COW_H_
#define COW_H_

#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>

class Cow {
public:
    std::string name;
    int l, u, m, food, meal;
    Cow(std::string nn, int ll, int uu, int mm);
    Cow();
};

#endif