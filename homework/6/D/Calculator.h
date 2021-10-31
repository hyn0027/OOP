//Calculator.h

#pragma once

#include "PerformStrategy.h"
#include "LevelStrategy.h"

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

class Calculator {
private:
    PerformStrategy *p;
    LevelStrategy *l;
public:
    Calculator(LevelStrategy *_l, PerformStrategy *_p) {
        p = _p;
        l = _l;
    }
    int get_base() {
        return l -> get_basis();
    }
    int get_total(int base) {
        return base + (p -> cnt_bonus(base));
    }
};