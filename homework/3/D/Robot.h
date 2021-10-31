//Robot.h
#pragma once

#include "Part.h"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

class Robot {
private:
    int tools_need;
    Part *tools;
    int tail;
public:
    string name = "Robot";
    Robot(int val);
    void add_part(Part p);
    bool is_full();
    friend ostream& operator<<(std::ostream& out, const Robot& x);
    int run();
    Part get_tool(int x);
    int get_tools_need();
    ~Robot();
};