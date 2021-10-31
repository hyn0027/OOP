//Alice.cpp
#include "Alice.h"
#include "Robot.h"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int Alice::run() {
    int ret = 0;
    for (int i = 0; i < get_tools_need(); i++)
        ret += get_tool(i).get_w();
    return ret;
}