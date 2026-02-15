#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>	
using namespace std;

struct MyType {
	int val1;
	double val2;
};	// 自定义类

int main() {

	// 动态数组vector 初始化 构造
	//vector<int> vec1;	// vector不是类型，是类的模板 vector<type>才是类型
	//vector<double> vec2;
	//vector<MyType> vec3;
	//vector< vector<int> > vec4;	// 动态数组的动态数组 二维数组
	//vector<int> arr[10];	// 动态数组的静态数组，静态数组内每个元素都是动态数组；图算法：邻接表

	//vector<int> vec2(100);	// 一开始就有100个元素，相当于初始化时申请了100个int的内存

	// 增
	// push_back 往vector尾部插入
	/*int a;
	while (scanf("%d", &a) != EOF) {
		vec1.push_back(a);
	}*/

	// 查
	//vector<int> vec1 = { 1,3,5,7,9 };
	//int i = 0;
	//printf("vec1[i] = %d\n", vec1[i]);
	//i = 3;
	//printf("vec1[i] = %d\n", vec1[i]);
	////i = 5;	// 越界
	////printf("vec1[i] = %d\n", vec1[i]);
	//int size = vec1.size();	// 动态数组容量
	//for (int i = 0; i < size; ++i) {
	//	printf("vec1[%d] = %d\n", i,vec1[i]);	// 按位查找
	//}

	// 迭代器
	//vector<int> vec1 = { 1,3,5,7,9 };
	/*vector<int>::iterator it;
	for (it = vec1.begin(); it != vec1.end(); ++it) {
		printf("*it = %d\n", *it);
	}*/
	//vector<int>::iterator it;
	//it = vec1.begin();	// 迭代器获取元素位置
	//vec1.insert(it, 2);	// 变成2 1 3 5 7 9	insert修改vector结构，在指定位置it前插入值2  插入后it的指向无意义
	//it = vec1.begin();
	//it = it + 3;	// 相当于3次++ 只能在vector迭代器中使用
	//vec1.insert(it, 6);	// 2 1 3 6 5 7 9

	vector<int> vec1 = { 1,3,5,7,9 };
	//vec1.clear();	// 清空所有数据
	//vec1.pop_back();	// 删除最后一个元素
	/*vector<int>::iterator it;
	it = vec1.begin() + 2;
	vec1.erase(it);*/

	// vector的方法
	// size begin end push_back pop_back insert clear erase


	list<int> ls1 = { 1,3,5,7,9 };
	list<int>::iterator it = ls1.begin();
	++it;
	++it;
	printf("*it = %d\n", *it);
	ls1.erase(it);	// list中使用erase和insert 效率更高

	for (it = ls1.begin(); it != ls1.end(); ++it) {
		printf("after erase, *it = %d\n", *it);
	}

	// list的方法 实质为双向链表
	// pop_front pop_back push_front push_back

	return 0;
}