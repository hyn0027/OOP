#include <iostream>
using namespace std;

class Base {
    int* x;
public:
    Base(){x = new int[10];}
    Base(const Base& other){fn();} // (1)
    virtual void fn(){cout << 1 << endl;}
    virtual void g1(){}
    virtual Base& g2(){}
    ~Base(){delete [] x;}
};

class Derive: public Base {
    int* y;
public:
    Derive(){y = new int[10];}
    Derive(const Derive& other):Base(other){fn();}
    void fn(){cout << 2 << endl;}
    void g1() const {}
    Derive& g2(){}
    ~Derive(){delete [] y;}
};

void fn(){
    Derive a;
    Derive b(a);
}

int main(){
    fn();
    return 0;
}