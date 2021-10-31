#ifndef __ITERATORBASE
#define __ITERATORBASE

class IteratorBase {
    
protected:
    int* data;
    int idx;

public:

    IteratorBase(int* _data, int _idx): data(_data), idx(_idx) {

    }

    bool operator !=(IteratorBase&& a) {return idx != a.idx;}
    int operator*() {return *data;}
};


#endif