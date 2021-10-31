#include <iostream>
using namespace std;
class B {
public:
   B(int i) {}
//   B(){}
};

class A {
private:
   int a = 1;
   B b;   // (2)
public:
   A() = default; // (1)
   A(int i):a(i), b(i) {}
};
int main() {
   A a();
   B b(1);
  return 0;
}