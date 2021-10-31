//Chat.h
#pragma once

#include "Person.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>

class Chat {
private:
    std::list<Person> man;
public:
    Chat();
    void add(std::string name, std::string word);
    void output();
};