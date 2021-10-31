#ifndef __LINEARDATASTRUCT
#define __LINEARDATASTRUCT

class LinearDataStruct {

protected:
    int data[1000];
    int idx_begin;
    int idx_end;
    int max_n;
    int n;

public:

    LinearDataStruct(int _n = 0):idx_begin(0), idx_end(0), max_n(_n), n(0) {

    }

    void push(int x);
    virtual int pop() {return 1;}
    int max_size() {return max_n;}
    int size() {return n;}
};

#endif