#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;


int main() {
	int n;
	priority_queue<int> pqueue;	// 存储权值相反数
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int leaf;
		scanf("%d", &leaf);
		pqueue.push(-1 * leaf);
	}
	int wpl = 0;
	while (pqueue.size() >= 2) {
		int leaf1 = pqueue.top();
		pqueue.pop();
		int leaf2 = pqueue.top();
		pqueue.pop();
		wpl += leaf1 + leaf2;
		pqueue.push(leaf1 + leaf2);
	}
	printf("%d\n", -1 * wpl);

	return 0;
}