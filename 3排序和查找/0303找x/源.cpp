#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &vec[i]);
	}
	int x;
	scanf("%d", &x);

	// 循环遍历查找
	/*int idx;
	for (idx = 0; idx < n; ++idx) {
		if (vec[idx] == x) {
			printf("%d\n", idx);
			return 0;
		}
	}
	if (idx == n) {
		printf("-1\n");
	}*/

	// 泛型算法 find(beginIt,endIt,x)
	vector<int>::iterator it;
	it = find(vec.begin(), vec.end(), x);
	if (it == vec.end()) {
		printf("-1\n");
	}
	else {
		// it+1 偏移	it-vec.begin() 偏移量
		printf("%d\n", it - vec.begin());
	}
	return 0;
}