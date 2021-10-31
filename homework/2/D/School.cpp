//Schol.cpp
#include "School.h"


#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//合查询信息的同学如果有多个，则输出返校时间最晚的同学里学号最大的同学的信息（学号可看作数字进行大小比较）

School::School(int num) {
    n = num;
    cnt = 0;
    s = new Student[n];
}

void School::add_member(Student x) {
    s[cnt] = x;
    //cout << "!" << x.name << " " << x.id << " " << x.province << " " << x.grade << " " << x.ret_time << endl;
    cnt++;
    if (cnt == n) {
        sort (s, s + n);
    }
}


Student School::operator[](const int sid) {
    for (int i = 0; i < n; i++)
        if (atoi(s[i].id.c_str()) == sid)
            return s[i];
    Student ss;
    ss.grade = "A";
    return ss;
}

Student School::operator[](const string name){
    for (int i = 0; i < n; i++)
        if (s[i].name == name)
            return s[i];
    Student ss;
    ss.grade = "A";
    return ss;
}

Student School::operator[](const char province) {
    for (int i = 0; i < n; i++)
        if (province == s[i].province[0])
            return s[i];
    Student ss;
    ss.grade = "A";
    return ss;
}