#ifndef __STACK
#define __STACK

#include "LinearDataStruct.h"
#include "IteratorBase.h"

class Stack: public LinearDataStruct {
    // TODO
public:

    class Iterator: public IteratorBase {
    public:
        using IteratorBase::IteratorBase;
        Iterator operator++(int) {
            Iterator ret(*this);
            data++;
            idx = (idx + 1) % 1000;
            return ret;
        }
        Iterator operator++() {
            data++;
            idx = (idx + 1) % 1000;
            return *this;
        }
    };

    Stack(int x): LinearDataStruct(x){};
    int pop();
    Iterator end();
    Iterator begin();
};


#endif