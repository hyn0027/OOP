//Bob.cpp
#include "Bob.h"
#include "Robot.h"

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

static int square(int x) {
    return x * x;
}

int Bob::run() {
    int ret = 0;
    for (int i = 0; i < get_tools_need(); i++)
        ret += square(get_tool(i).get_w());
    return ret;
}