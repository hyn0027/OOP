#include <iostream>
#include "Example.h"

using namespace std;

int Example::cnt = 0;

Example::Example(int data) {
	m_data = data;
	cnt++;
	id = cnt;
	cout << "Example #" << id << " is created" << endl;
}

void Example::getData() {
	cout << "The data of Example #" << id << " is " << m_data << endl;
}

Example::~Example() {
	cout << "Example #" << id << " is destroyed" << endl;
}