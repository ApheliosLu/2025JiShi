#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);	// 编号1，2，3，……，n
	// 用图来存储树，邻接表法
	vector<vector<int>> tree(n + 1);	// tree[0]不起作用
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	queue<int> toVisit;	// 用于BFS的队列
	toVisit.push(m);
	vector<int> distance(n + 1);	// 记录某个结点是否访问过；若访问过，还可以记录根节点到该节点的距离
	for (int i = 1; i <= n; ++i) {
		distance[i] = -1;
	}
	distance[m] = 0;	// 根到根的距离是0
	int maxdistance = 0;
	while (toVisit.empty() == false) {	// 访问完后退出循环
		int current = toVisit.front();
		toVisit.pop();
		for (int i = 0; i < tree[current].size(); ++i) {
			int child = tree[current][i];
			if (distance[child] != -1) {
				continue;	// 不是孩子
			}
			toVisit.push(child);	// 是孩子
			distance[child] = distance[current] + 1;
			maxdistance = distance[child];
		}
	}
	printf("%d\n", maxdistance);
	return 0;
}