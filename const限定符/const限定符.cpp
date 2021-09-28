#include <iostream>
#include <string>
using namespace std;
//1.不允许修改常量的值
void test1() {
	const int i = 1;
	//不允许修改常量的值
	//i = 2;
}

//2.常量必须初始化，因为不允许修改常量值
void test2() {
	//const int i1;
	//i1 = 2;
}

//3.全局变量只能被定义一次，在使用的时候需要先声明
//int val = 3;  //val已经被定义过了，所以不能在定义
//使用extern关键字声明一个全局变量
extern int val;
void test3() {
	cout << val << endl;
}

//4.全局常量且在当前文件中有效
//在不同文件中定义的同名常量，实际是不同的对象
//因此多个文件中可以定义同名常量，但同一文件中不能定义多个同名常量
const int const_val = 10086;
extern void constMethod();
void test4() {
	cout << "main文件中定义的常量const_val : " << const_val << "，" << &const_val << endl;
	constMethod();
}

//5.多个文件使用同一个常量
//在定义和声明常量时都要使用extern关键字，只能被定义一次
//extern const int extern_const_val = 400;
extern const int extern_const_val;
void test5() {
	cout << extern_const_val << endl;
}

//6.const引用
void test6() {
	int val = 10;
	const int const_val = 20;

	int& ref1 = val;
	//非常量引用不能引用一个常量，因为可通过引用改变其值
	//int& ref2 = const_val;

	const int& const_ref1 = val;
	const int& const_ref2 = const_val;
}

int main()
{
	test5();
	return 0;
}
