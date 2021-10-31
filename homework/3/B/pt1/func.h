#include "Test.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

/*
	cout << "------entering main------" << endl;
	Test a;
	Test b;
	
	cout << "------before call f1------" << endl;
	
	cout << "f1():" << endl;
	Test A = f1(a);
	
	cout << "------after f1 return------" << endl;
	
	cout << "------before call f2------" << endl;
	
	cout << "f2():" << endl;
	Test& B = f2(b);
	
	cout << "------after f2 return------" << endl;
	
	cout << "------before call f3------" << endl;
	
	cout << "f3():" << endl;
	f3(a, b);
	
	cout << "------after f3 return------" << endl;
	
	cout << "------exiting main------" << endl;
	
*/

Test f1(Test a) {
    a.print("a");
    return a;
}

Test& f2(Test& b) {
    b.print("b");
    return b;
}

void f3(Test& a, Test& b) {
    swap(a, b);
}