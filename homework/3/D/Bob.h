//Bob.h
#pragma once

#include "Robot.h"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

class Bob: public Robot {
public:
    Bob(int val): Robot(val) {name = "Bob";}
    int run();
};