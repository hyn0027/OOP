#include "Test.h"
#include <iostream>

using namespace std;

const Test& F(const Test& a){
    Test b = a;
    return Test(1);
}
int main() {
    Test a;
    const Test &A = F(std::move(a));
    A.print("A");
    return 0;
}