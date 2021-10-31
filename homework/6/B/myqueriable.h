//myqueriable.h
#pragma once

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

template<class T> class MyQueriable {
public:
    T s;
    template<class Func1> MyQueriable where(Func1 func) {
        MyQueriable ret;
        ret.s.clear();
        for (auto it : s) {
            if(func(it))   ret.s.push_back(it);
        }
        return ret;
    }
    template<class Func2> MyQueriable apply(Func2 func) {
        MyQueriable ret;
        ret.s.clear();
        for (auto it : s)
            ret.s.push_back(func(it));
        return ret;
    }
    auto sum() {
        auto ret = 0;
        for (auto it : s)
            ret += it;
        return ret;
    }
    auto operator[](int idx) {
        auto it = s.begin();
        for (int i = 0; i < idx; i++) 
            it++;
        return *it;
    }
    int size() {
        return s.size();
    }
};
template<class T>
MyQueriable<T> from(T s) {
    MyQueriable<T> ret;
    ret.s.clear();
    for (auto it : s)
        ret.s.push_back(it);
    return ret;
}