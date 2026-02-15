#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) {
			break;
		}
		vector<int> vec(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &vec[i]);
		}
		bool isOdd = (n % 2 == 1);
		priority_queue<int> pqueue;
		int size = n / 2 + 1;
		for (int i = 0; i < size; ++i) {
			pqueue.push(-1 * vec[i]);	// 相反数入队保持小根堆
		}
		for (int i = size; i < n; ++i) {
			int top = pqueue.top();	// 前size个数中，最小元素的相反数
			if (-top < vec[i]) {
				pqueue.pop();
				pqueue.push(-vec[i]);
			}
		}
		if (isOdd) {
			int mid = -pqueue.top();
			printf("%d\n", mid);
		}
		else {
			int mid1 = -pqueue.top();
			pqueue.pop();
			int mid2 = -pqueue.top();
			printf("%d\n", (mid1 + mid2) / 2);
		}
	}

	return 0;

}