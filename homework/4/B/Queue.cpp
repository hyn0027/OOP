#include "Queue.h"

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int Queue::pop() {
    int ret = data[idx_begin];
    idx_begin = (idx_begin + 1) % 1000;
    n--;
    return ret;
}

Queue::Iterator Queue::begin() {
    return Iterator(&data[idx_begin], idx_begin);
}

Queue::Iterator Queue::end() {
    return Iterator(&data[idx_end], idx_end);
}