//School.h
#pragma once

#include "Student.h"

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class School {
private:
    int n, cnt;
    Student *s;
public:
    School(int num);
    void add_member(Student x);
    Student operator[](const int sid);
    Student operator[](const string name);
    Student operator[](const char province);
    ~School() {
        delete[] s;
    }
};