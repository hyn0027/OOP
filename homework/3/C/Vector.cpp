#include "Vector.h"
#include "Node.h"

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

Vector::Vector(int n) {
    capacity = n;
    len = 0;
    array = new Node[n];
}

Vector::~Vector() {
    delete[] array;
}

Vector::Vector(const Vector & other) {
    capacity = other.capacity;
    len = other.len;
    array = new Node[capacity];
    for (int i = 0; i < len; i++)
        array[i] = other.array[i];
}

Vector::Vector(Vector && other) {
    array = other.array;
    len = other.len;
    capacity = other.capacity;
    other.array = nullptr;
    other.len = 0;
    other.capacity = 0;
}

Vector& Vector::operator=(const Vector & other) {
    if (this != &other) {
        if (capacity < other.capacity) {
            if (array)  delete[] array;
            array = new Node[other.capacity];
        }
        capacity = other.capacity;
        len = other.len;
        for (int i = 0; i < len; i++)
            array[i] = other.array[i];
    }
    return *this;
}

Vector& Vector::operator=(Vector && other) {
    if (this != &other) {
        if (array)  delete[] array;
        array = other.array;
        other.array = nullptr;
        capacity = other.capacity;
        len = other.len;
        other.len = 0;
        other.capacity = 0;
    }
    return *this;
}

Node& Vector::operator [] (int pos) {
    return array[pos];
}

void Vector::append(int value) {
    array[len] = value;
    len++;
}

void Vector::insert(int pos, int value) {
    for (int i = len - 1; i >= pos; i--) {
        //move array[i] to array[i + 1]
        array[i + 1] = move(array[i]);
    }
    array[pos] = value;
    len++;
}

void Vector::swap(int pos1, int pos2) {
    Node tmp = move(array[pos1]);
    array[pos1] = move(array[pos2]);
    array[pos2] = move(tmp);
}

void Vector::dilatation() {
    Node* tmp = new Node[capacity * 2];
    for (int i = 0; i < len; i++)
        tmp[i] = move(array[i]);
    delete[] array;
    capacity *= 2;
    array = move(tmp);
    tmp = nullptr;
}

int Vector::getlen() {
    return len;
}