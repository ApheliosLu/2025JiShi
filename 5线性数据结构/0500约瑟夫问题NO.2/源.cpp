#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int main() {
	// 先进先出 队列 循环结构（出了再入）
	queue<int> myQueue;
	int n, p, m;
	while (1) {
		scanf("%d%d%d", &n, &p, &m);
		if (n == 0 && p == 0 && m == 0) {
			break;
		}

		//  生成第一轮报数队列
		// p,p+1,p+2,...,n,1,2,...,p-1
		int no=p;	// no是孩子编号
		for (int i = 0; i < n; ++i) {
			myQueue.push(no);
			++no;
			if (no > n) {
				no = 1;
			}
		}

		// 开始报数
		int say = 1;	// say是报的数字
		while (1) {
			int cur = myQueue.front();
			myQueue.pop();
			if (say == m) {
				say = 1;
				if (myQueue.empty()) {
					printf("%d\n",cur);
					break;
				}
				else {
					printf("%d,", cur);
				}
			}
			else {
				++say;
				myQueue.push(cur);
			}
		}

	}

	return 0;
}