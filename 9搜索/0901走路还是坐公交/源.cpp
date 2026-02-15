#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main() {
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF) {
		int time = 0;
		queue<int> posQueue;
		vector<int> curtime(100001);	// 元素值为零表示某个位置未被访问
		posQueue.push(n);
		curtime[n] = 1;	// 记录访问某位置的时间+1
		while (posQueue.empty() == false) {
			int top = posQueue.front();
			posQueue.pop();
			time = curtime[top];
			if (top == k) {
				printf("%d\n", time - 1);
				break;
			}
			// BFS
			if (2 * top <= 100000 && curtime[2 * top] == 0) {
				posQueue.push(2 * top);
				curtime[2 * top] = time + 1;
			}
			if (top - 1 >= 0 && curtime[top - 1] == 0) {
				posQueue.push(top - 1);
				curtime[top - 1] = time + 1;
			}
			if (top + 1 <= 100000 && curtime[top + 1] == 0) {
				posQueue.push(top + 1);
				curtime[top + 1] = time + 1;
			}
		}
	}

	return 0;
}