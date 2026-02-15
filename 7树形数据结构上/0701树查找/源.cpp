#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> tree(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tree[i]);
	}
	int beg = 0;
	int end = 0;
	int k;
	scanf("%d", &k);
	for (int i = 1; i < k; ++i) {
		beg = beg * 2 + 1;
		end = end * 2 + 2;
	}	// beg和end是第k层的起点和终点下标
	if (beg >= tree.size()) {
		printf("EMPTY\n");
	}
	else {
		for (int i = beg; i <= end && i < tree.size(); ++i) {
			printf("%d ", tree[i]);
		}
		printf("\n");
	}
	return 0;
}