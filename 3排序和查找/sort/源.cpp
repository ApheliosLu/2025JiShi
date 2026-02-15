#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int lhs, int rhs) {	// 自定义排序规则
	return lhs >= rhs;
}

int main() {
	int arr[6] = { 2,4,6,1,3,5 };
	// sort(起始地址，尾后地址)	左闭右开 底层快排 默认递增
	sort(arr, arr + 6);		// 两个参数都是指针
	vector<int> vec = { 2,4,6,1,3,5 };
	sort(vec.begin(), vec.end());	// 两个参数都是迭代器	不同的函数使用同一个名字：函数重载

	// 降序排序
	sort(vec.begin(), vec.end(), compare);
	return 0;
}