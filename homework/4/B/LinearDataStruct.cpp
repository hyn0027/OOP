#include "LinearDataStruct.h"

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

void LinearDataStruct::push(int x) {
    data[idx_end] = x;
    idx_end = (idx_end + 1) % 1000;
    n++;
}