#pragma once

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 1000 + 5;

template<class A>
class Container{
private:
    int tiezi[maxn], huifu[maxn], tail;
    A name[maxn]; 
public:
    Container(){
        tail = 0;
    }
    void insert(int tz, int hf, A nm) {
        tiezi[tail] = tz;
        huifu[tail] = hf;
        name[tail] = nm;
        tail++;
    }
    A* find(int tz, int hf) {
        for (int i = 0; i < tail; i++)
            if (tiezi[i] == tz && huifu[i] == hf)
                return &name[i];
        return NULL;
    }
};