//LevelStrategy.h

#pragma once

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

class LevelStrategy {
public:
    virtual int get_basis(){
        return 0;
    }
};

class P1LStrategy : public LevelStrategy {
public:
    int get_basis() {
        return 2000;
    }
};

class P2LStrategy : public LevelStrategy {
public:
    int get_basis() {
        return 5000;
    }
};

class P3LStrategy : public LevelStrategy {
public:
    int get_basis() {
        return 10000;
    }
};