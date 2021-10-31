// Parser.h

#ifndef _PARSER_H_
#define _PARSER_H_

#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

class Parser{
private:
    int num[5];
    std::map<std::string, int> mp1;
    std::map<std::string, std::string> mp2;
    std::vector<std::string> v;
public:
    Parser();
    void add_argument(std::string tag1, int id, std::string tag2);
    void init(int argc, char *argv[]);
    int get_argument(std::string tag);
    void get_help_information();
    void print_usage();
    bool is_integer(char* s);
    void upper(std::string x);
};

#endif