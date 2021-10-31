//Chat.cpp
#include "Chat.h"
#include "Person.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>

Chat::Chat() {}

void Chat::add(std::string name, std::string word) {
    for (auto it = man.begin(); it != man.end(); ++it) {
        if (it -> same(name)) {
            it -> add(word);
            Person tmp = *it;
            man.erase(it);
            man.push_front(tmp);
            return;
        }
    }
    Person tmp(name);
    tmp.add(word);
    man.push_front(tmp);
    return;
}

void Chat::output() {
    for (auto it = man.begin(); it != man.end(); ++it)
        it -> output();
}