//Student.h
#pragma once

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Student {
public:
    string name, province, grade, ret_time, id;
    friend istream& operator>> (istream& in, Student& dst) {
        string information;
        in >> information;
        //[姓名]-[省份]-[年级]-[返校时间]-[学号]
        int idx = 0, bef;
        while(information[idx] != '-')  idx++;
        dst.name = information.substr(0, idx);
        bef = idx;
        idx++;
        while(information[idx] != '-')  idx++;
        dst.province = information.substr(bef + 1, idx - bef - 1);
        bef = idx;
        idx++;
        while(information[idx] != '-')  idx++;
        dst.grade = information.substr(bef + 1, idx - bef - 1);
        bef = idx;
        idx++;
        while(information[idx] != '-')  idx++;
        dst.ret_time = information.substr(bef + 1, idx - bef - 1);
        bef = idx;
        dst.id = information.substr(bef + 1);
        return in;
    }
    friend ostream& operator<< (ostream& out, const Student& src) {
        //[姓名]-[返校时间]-[年级]-[学号]
        if (src.grade == "A") {
            out << "Not Found" << endl;
            return out;
        }
        out << src.name << "-" << src.ret_time << "-" << src.grade << "-" << src.id << endl;
        return out;
    }
    friend bool operator <(const Student& s1, const Student& s2) {
        if (s1.ret_time != s2.ret_time)
            return s1.ret_time > s2.ret_time;
        return s1.id > s2.id;
    }
};
