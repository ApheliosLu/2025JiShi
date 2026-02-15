#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 10;

struct Edge {
	int from;
	int to;
	int length;
	bool operator< (const Edge& e) const {
		return length < e.length;
	}
};

Edge edge[MAXN * MAXN];	// 边集
int father[MAXN];	// 父亲结点
int height[MAXN];	// 结点高度

void Initial(int n) {
	for (int i = 0; i < n; ++i) {
		father[i] = i;
		height[i] = 0;
	}
}

int Find(int x) {
	if (x != father[x]) {
		father[x] = Find(father[x]);	// 路径压缩
	}
	return father[x];
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		if (height[x] < height[y]) {	// 矮树作为高树的子树
			father[x] = y;
		}
		else if (height[y] < height[x]) {
			father[y] = x;
		}
		else {
			father[y] = x;
			height[x]++;
		}
	}
	return;
}

int Kruskal(int n, int edgeNumber) {
	Initial(n);
	sort(edge, edge + edgeNumber);	// 按权值排序
	int sum = 0;
	for (int i = 0; i < edgeNumber; ++i) {
		Edge current = edge[i];
		if (Find(current.from) != Find(current.to)) {
			Union(current.from, current.to);
			sum += current.length;
		}
	}
	return sum;
}
int main() {
	int N;
	while (scanf("%d", &N) != EOF) {
		if (N == 0) {
			break;
		}
		int edgeNumber = N * (N - 1) / 2;
		for (int i = 0; i < edgeNumber; ++i) {
			int status;
			scanf("%d%d%d%d", &edge[i].from, &edge[i].to, &edge[i].length, &status);
			if (status == 1) {
				edge[i].length = 0;
			}
		}
		int answer = Kruskal(N, edgeNumber);
		printf("%d\n", answer);
	}
	return 0;
}