#include "Stack.h"

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int Stack::pop() {
    int ret = data[idx_end - 1];
    idx_end = (idx_end - 1 + 1000) % 1000;
    n--;
    return ret;
}


Stack::Iterator Stack::begin() {
    return Iterator(&data[idx_begin], idx_begin);
}

Stack::Iterator Stack::end() {
    return Iterator(&data[idx_end], idx_end);
}