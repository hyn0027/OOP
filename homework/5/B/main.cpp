//main.cpp
#include "Chat.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    Chat my_chat;
    while (n--) {
        std::string name, words, tmp;
        std::cin >> name >> words;
        int l = 0, r = 0;
        while (r < words.size()) {
            while (words[r] != '/' && r < words.size()) r++;
            tmp.assign(words, l, r - l);
            my_chat.add(name, tmp);
            l = ++r;
        }
    }
    std::cin >> n;
    while (n--) {
        std::string name, words;
        std::cin >> name >> words;
        my_chat.add(name, words);
    }
    my_chat.output();
    return 0;
}