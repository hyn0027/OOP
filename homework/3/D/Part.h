//Part.h
#pragma once

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

class Part {
private:
int w;
public:
    Part(int id): w(id){};
    Part(){}
    int get_w() {return w;}
};