#pragma once

#include "operation.h"

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

class Minus: public OperationNodeTwo {
public:
    Minus(string name, Node *x1, Node *x2): OperationNodeTwo(name, x1, x2) {}
    void UpdateValue() {
        value_ = (input1 -> value()) - (input2 -> value());
    }
};