//Robot.cpp
#include "Robot.h"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

Robot::Robot(int val) {
    tools_need = val;
    tools = new Part[tools_need + 1];
    tail = 0;
}

void Robot::add_part(Part p) {
    tools[tail++] = p;
}

bool Robot::is_full() {
    return (tail == tools_need);
}

ostream& operator<<(std::ostream& out, const Robot& x) {
    out << "Build robot " << x.name;
    return out;
}

int Robot::run() {
    return 0;
}

Part Robot::get_tool(int x) {
    return tools[x];
}

int Robot::get_tools_need(){
    return tools_need;
}

Robot::~Robot() {
    delete[] tools;
}