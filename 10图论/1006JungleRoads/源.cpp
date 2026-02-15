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
	Edge(){}	// 默认构造函数
	Edge(int f,int t,int l):from(f),to(t),length(l){}	// 带参数的构造函数：构造函数名，成员初始化列表，函数体（这里为空）
	bool operator< (const Edge& e) const {
		return length < e.length;
	}
};

Edge edge[MAXN * MAXN];	// 边集
int father[MAXN];
int height[MAXN];

// 并查集初始化、查找、合并
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

// Kruskal最小生成树
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
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) {
			break;
		}
		int edgeNumber = 0;
		for (int i = 0; i < n - 1; ++i) {
			char from;
			int number;
			cin >> from >> number;
			for (int j = 0; j < number; ++j) {
				char to;
				int length;
				cin >> to >> length;
				edge[edgeNumber++] = Edge(from - 'A', to - 'A', length);
			}
		}
		int answer = Kruskal(n, edgeNumber);
		printf("%d\n", answer);
	}
	return 0;
}