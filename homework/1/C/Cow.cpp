//Cow.cpp
#include "Cow.h"

#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>

Cow::Cow(std::string nn, int ll, int uu, int mm) {
    name = nn;
    l = ll;
    u = uu;
    m = mm;
    food = 0;
}

Cow::Cow(){}