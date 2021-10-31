//PerformStrategy.h

#pragma once

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

class PerformStrategy {
private:
    double perform;
public:
    PerformStrategy(double _perform) {
        perform = _perform;
    }
    double get_perform() {
        return perform;
    }
    virtual int cnt_bonus(int basis) {
        return 0;
    }
};

class sPerformStrategy : public PerformStrategy {
public:
    using PerformStrategy::PerformStrategy;
    int cnt_bonus(int basis) {
        return 1000;
    }
};

class mPerformStrategy : public PerformStrategy {
public:
    using PerformStrategy::PerformStrategy;
    int cnt_bonus(int basis) {
        return (int)(get_perform() * basis);
    }
};

class lPerformStrategy : public PerformStrategy {
public:
    using PerformStrategy::PerformStrategy;
    int cnt_bonus(int basis) {
        return (int)(get_perform() * basis * 2);
    }
};