//Alice.h
#pragma once

#include "Robot.h"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

class Alice: public Robot {
public:
    Alice(int val): Robot(val) {name = "Alice";}
    int run();
};