#ifndef __QUEUE
#define __QUEUE

#include "LinearDataStruct.h"
#include "IteratorBase.h"

class Queue: public LinearDataStruct {
    // TODO
public:

    class Iterator: public IteratorBase {
    public:
        using IteratorBase::IteratorBase;
        Iterator operator++(int) {
            Iterator ret(*this);
            data++;
            if (idx == 999)
                data -= 1000;
            idx = (idx + 1) % 1000;
            return ret;
        }
        Iterator operator++() {
            data++;
            if (idx == 999)
                data -= 1000;
            idx = (idx + 1) % 1000;
            return *this;
        }
    };

    Queue(int x): LinearDataStruct(x){}
    int pop();
    Iterator begin();
    Iterator end();
};

#endif