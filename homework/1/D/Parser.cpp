//Parser.cpp
#include "Parser.h"

#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

Parser::Parser() {
    mp1.clear();
    v.clear();
}

void Parser::add_argument(std::string tag1, int id, std::string tag2) {
    mp1[tag1] = id;
    mp2[tag1] = tag2;
    v.push_back(tag1);
    return;
}

void Parser::upper(std::string s) {
    for (int i = 2; i < s.size(); i++)
        std::cout << (char)(s[i] + 'A' - 'a');
    return;
}

void Parser::print_usage() {
    printf("usage: ./main [--help]");
    for (int i = 0; i < v.size(); i++) {
        std::cout << " [" << v[i] << " ";
        upper(v[i]);
        std::cout << "]";
    }
    printf("\n");
    return;
}

void Parser::get_help_information() {
    print_usage();
    printf("\noptional arguments:\n");
    printf("--help   show this help message and exit\n");
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
        upper(v[i]);
        std::cout << "   " << mp2[v[i]] << std::endl;
    }
    return;
}

bool Parser::is_integer(char* s) {
    for (int i = 0; i < strlen(s); i++)
        if (s[i] < '0' || s[i] > '9')
            return false;
    return true;
}

void Parser::init(int argc, char *argv[]) {
    bool help = false;
    for (int i = 1; i < argc; i++) {
        if ((std::string)argv[i] == "--help") {
            help = true;
            break;
        }
    }
    if (help) {
        get_help_information();
        exit(0);
    }
    for (int i = 1; i < argc; i+=2) {
        std::map<std::string, int>::iterator iter;
        iter = mp1.find((std::string)argv[i]);
        if (iter == mp1.end()) {
            print_usage();
            printf("./main: error: unrecognized arguments: %s\n", argv[i]);
            exit(0);
        }
        if (i == argc - 1) {
            print_usage();
            printf("./main: error: argument %s: expected an argument\n", argv[i]);
            exit(0);
        }
        if (!is_integer(argv[i + 1])) {
            print_usage();
            printf("./main: error: argument %s: invalid int value: '%s'\n", argv[i], argv[i + 1]);
            exit(0);
        }
        mp1[(std::string)argv[i]] = atoi(((std::string)argv[i + 1]).c_str());
    }
}

int Parser::get_argument(std::string tag){
    tag = "--" + tag;
    return mp1[tag];
}