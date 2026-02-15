#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>	
#include <set>
#include <unordered_set>
using namespace std;

int main() {
	// 构造set
	set<int> set1 = { 1,3,5 };
	multiset<int> set2 = { 1,3,5,1,3,5 };
	unordered_set<int> set3 = { 2,4,6 };
	unordered_multiset<int> set4 = { 2,4,6,2,4,6 };

	// 迭代器遍历
	unordered_multiset<int>::iterator it;
	for (it = set4.begin(); it != set4.end(); ++it) {
		printf("%d ", *it);
	}
	printf("\n");

	// 查找元素位置find，找不到返回尾后迭代器
	if (set3.find(2) == set3.end()) {
		printf("2 is not in set3!\n");
	}
	else {
		printf("2 is in set3!\n");
	}

	// count获取元素数量
	printf("2 occurs %d times\n", set4.count(2));

	// set元素不允许修改，可以先删除再插入

	//// 新增元素
	//set1.insert(2);
	//set1.insert(1);
	//set2.insert(2);
	//set2.insert(1);

	//// 删除元素
	//set1.erase(1);
	//set2.erase(1);	// 会删除所有1
	return 0;
}