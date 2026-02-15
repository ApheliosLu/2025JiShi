#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	// map 代替二分查找
	map<int, int> findA;
	for (int i = 0; i < n; ++i) {
		findA.insert({ a[i],i });
	}
	int m;
	scanf("%d", &m);
	int b;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b);
		if (findA.find(b) == findA.end()) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}

	// 二分查找 先排序再查找
	/*sort(a.begin(), a.end());
	int m;
	scanf("%d", &m);
	int b;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b);
		int left = 0;
		int right = n - 1;
		while (left<=right) {
			int mid = (left + right) / 2;
			if (b == a[mid]) {
				printf("YES\n");
				break;
			}
			else if (b < a[mid]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		if (left > right) {
			printf("NO\n");
		}
	}*/

	return 0;
}