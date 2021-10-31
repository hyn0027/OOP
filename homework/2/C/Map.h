#pragma once
#include "Pair.h"

class Map{
    Pair * data;
    int sz;
public:
    Map(int n);
    int& operator[](const string s);
    int operator[] (const string s) const;
    int size();
    ~Map() {
        delete[] data;
    }
};