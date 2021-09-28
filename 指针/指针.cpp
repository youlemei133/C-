#include <iostream>
#include <string>
using namespace std;

//1.指针是一个对象，而引用不是对象
void test1() {
	int i = 10;
	int& ref = i;
	int* ptr = &i;

	cout << &i << endl;
	cout << &ref << endl;	//引用的地址和i地址一样，说明没有为引用分配内存
	cout << &ptr << endl;	//指针的地址和i地址不一样，说明为指针分配了内存
}

//2.指针可以指向多个对象，而引用只能绑定一个对象
void test2() {
	int i1 = 10;
	int i2 = 20;

	int* ptr = &i1;//指针指向i1
	ptr = &i2;//指针指向i2
	*ptr = 100;//i2的值发生改变
	cout << i1 << endl;	//10
	cout << i2 << endl; //100

	i1 = 10;
	i2 = 20;
	int& ref = i1;//引用与i1进行绑定
	ref = i2;//将i2的值赋值给引用的对象i1
	ref = 100;//修改i1的值
	cout << i1 << endl; //100
	cout << i2 << endl; //20
}

//3.指针可以不初始化，但是引用必须初始化
void test3() {
	int* ptr;//指针可以不初始化
	//int& ref;引用必须初始化

	//未初始化的指针，会分配内存空间
	cout << &ptr << " , " << sizeof(ptr) << endl;
	//由于未初始化，所以指针内存中存储的是一个无效地址
	//当访问一个无效地址时，会报错
	//cout << *ptr << endl;
	//cout << ptr << endl;
}

//4.不能定义引用的指针
void test4() {
	int i = 10;
	int& ref = i;

	int* ptr = &ref;	//这里对引用取地址操作，实际是对引用指向的变量取地址操作
	//定义引用的指针
	//int&* ref_ptr = &ref;	//编译不通过，因为引用并非一个对象
}

//5.指针需与它指向对象类型严格匹配
void test5() {
	double d = 10;
	int i = 20;

	int* ptr = &i;
	//ptr = &d;
}


//6.指针的值
void test6() {
	int i = 10;
	//1.指向一个对象
	int* ptr = &i;
	cout << *ptr << endl;

	//2.空指针
	int* ptr1 = nullptr;
	//访问空指针指向的对象将在运行时引发异常
	//cout << *ptr1 << endl;

	//3.无效指针
	int* ptr2 = (int*)0x000001;
	//访问无效指针指向的对象将在运行时引发异常
	//cout << *ptr2 << endl;
}

//7.指针访问对象
void test7() {
	int i = 10;
	int* ptr = &i;
	//使用解引用符获取指向的对象
	cout << *ptr << endl;
}

//8.空指针
void test8() {
	//3种空指针示法

	//nullptr是一个字面值
	int* ptr1 = nullptr;
	//NULL是一个预处理变量，预处理器在编译前会将该变量替换为0
	int* ptr2 = NULL;
	//使用0字面值来初始化空指针
	int* ptr3 = 0;

	int i = 0;
	//虽然i的值为0，但是不能使用一个对象来初始化指针
	//int* ptr4 = i;
}

//8.指针其他操作
void test9() {
	int i = 10;
	int* ptr1 = &i;
	int* ptr2 = nullptr;
	//非空指针为true，空指针为false
	if (ptr1)
		cout << "指针为true" << endl;
	if (!ptr2)
		cout << "空指针为false" << endl;

	//两个指针指向同一个对象，则这两个指针相等
	//但是这两个指针是不同对象
	int* ptr3 = &i;
	int* ptr4 = &i;
	bool b = ptr3 == ptr4;
	cout << b << endl;
}

//10.void* 指针，可指向任意类型对象，但是无法访问指向的对象
void test10() {
	int i = 10;
	double d = 20;

	//void*指向int对象
	void* ptr = &i;
	//void*指向double对象
	ptr = &d;
	//无法访问指向的对象
	//cout << *ptr << endl;
}
int main()
{
    std::cout << "Hello World!.....\n";
}

