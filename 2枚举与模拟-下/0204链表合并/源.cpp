#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>	
using namespace std;

int main() {
	int s1, s2, val;
	list<int> ls1, ls2;

	scanf("%d", &s1);
	for (int i = 0; i < s1; ++i) {
		scanf("%d",&val);
		ls1.push_back(val);
	}

	scanf("%d", &s2);
	for (int i = 0; i < s2; ++i) {
		scanf("%d", &val);
		ls2.push_back(val);
	}

	list<int>::iterator it1 = ls1.begin();
	list<int>::iterator it2 = ls2.begin();

	list<int> ls3;
	while (it1 != ls1.end() || it2 != ls2.end()) {
		if (it1 == ls1.end()) {  // ls1 已经遍历完，直接添加 ls2 的元素
			ls3.push_back(*it2);
			++it2;
		}
		else if (it2 == ls2.end()) {  // ls2 已经遍历完，直接添加 ls1 的元素
			ls3.push_back(*it1);
			++it1;
		}
		else if (*it1 > *it2) {  // 比较当前元素大小
			ls3.push_back(*it2);
			++it2;
		}
		else {
			ls3.push_back(*it1);
			++it1;
		}
	}
	list<int>::iterator it3;
	for (it3 = ls3.begin(); it3 != ls3.end(); ++it3) {
		printf("%d ", *it3);
	}
	printf("\n");
	return 0;
}