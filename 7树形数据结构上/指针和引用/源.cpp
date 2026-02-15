#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int* func() {
	int* p = new int;	// 堆空间 链式存储使用
	*p = 10;
	return p;
}
int main() {
	//int i = 10;
	//int* p;	// 指针变量p，指向一个int变量
	//p = &i;	// i的地址放入p中
	//++*p;	// 根据p找到指向的数据，再对数据自增
	int* p1;
	p1 = func();
	++*p1;
	delete p1;

	return 0;
}