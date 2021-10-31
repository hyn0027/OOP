//person.h
#pragma once

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

class Person {
private: 
std::vector<std::string> chat;
std::string name;
public:
    Person(std::string x);
    void add(std::string x);
    void output();
    bool same(std::string x);
};