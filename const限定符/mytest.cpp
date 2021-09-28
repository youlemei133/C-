#include <iostream>
#include <string>
using namespace std;
int val = 100;
const int const_val = 200;
extern const int extern_const_val = 300;

void constMethod() {
	cout << "其他文件中定义的常量const_val :" << const_val << "，" << &const_val << endl;
}