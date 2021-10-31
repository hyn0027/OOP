#include "Map.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

Map::Map(int n) {
    data = new Pair[n];
    sz = 0;
}

int& Map::operator[](const string s) {
    for (int i = 0; i < sz; i++) {
        if (data[i].hasKey(s))
            return data[i].getVal();
    }
    data[sz].reset(s, 0);
    sz++;
    return data[sz - 1].getVal();
}

int Map::operator[] (const string s) const {
    for (int i = 0; i < sz; i++) {
        if (data[i].hasKey(s))
            return data[i].getVal();
    }
    return 0;
}

int Map::size(){
    return sz;
}