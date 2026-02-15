#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>	
#include <set>
#include <unordered_set>
using namespace std;

int main() {

	// 小于一百万的阶乘有哪些	10的阶乘已超过一百万
	vector<int> factorialArr;
	factorialArr.push_back(1);	// 把0！放入数组
	int currentFactorial = 1;
	for (int i = 1; i <= 9; ++i) {	// 保存0到9的阶乘
		currentFactorial=currentFactorial* i;
		factorialArr.push_back(currentFactorial);
	}

	// 用空间换时间，先生成好所有可能性（0到9的阶乘是否出现，共1024中可能性）
	set<int> allPossible;	// 所有的阶乘和的可能性	allPossible 中的元素是所有可能的阶乘和的组合
	allPossible.insert(0);
	for (int i = 0; i <= 9; ++i) {
		set<int> tempSet;
		set<int>::iterator it;
		for (it = allPossible.begin(); it != allPossible.end(); ++it) {
			tempSet.insert(*it + factorialArr[i]);
		}
		for (it = tempSet.begin(); it != tempSet.end(); ++it) {
			allPossible.insert(*it);
		}
	}
	allPossible.erase(0);

	int n;
	while (scanf("%d", &n) != EOF) {
		if (n < 0) {
			break;
		}
		if (allPossible.count(n) == 0) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
	return 0;
}