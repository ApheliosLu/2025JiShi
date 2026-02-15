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
		priority_queue<int, vector<int>, greater<int>> myPriorityQueue;	// 另一种构建小根堆的方式
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			myPriorityQueue.push(x);
		}
		int answer = 0;
		while (1 < myPriorityQueue.size()) {
			int a = myPriorityQueue.top();
			myPriorityQueue.pop();
			int b = myPriorityQueue.top();
			myPriorityQueue.pop();
			answer += a + b;
			myPriorityQueue.push(a + b);
		}
		printf("%d\n", answer);
	}

	return 0;
}