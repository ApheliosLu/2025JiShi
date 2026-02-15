#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 100 + 10;

struct Edge {
	int from;
	int to;
	double length;
	bool operator< (const Edge& e) const {
		return length < e.length;
	}
};

struct Point {
	double x, y;
};

Point point[MAXN];
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
double Kruskal(int n, int edgeNumber) {
	Initial(n);
	sort(edge, edge + edgeNumber);	// 按权值排序
	double sum = 0;
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
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf", &point[i].x, &point[i].y);
		}
		int edgeNumber = n * (n - 1) / 2;
		int index = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				edge[index].from = i;
				edge[index].to = j;
				edge[index].length = sqrt(pow(point[i].x - point[j].x, 2) + pow(point[i].y - point[j].y, 2));	// 计算每条边距离
				index++;
			}
		}
		double answer = Kruskal(n, edgeNumber);
		printf("%.2f\n", answer);
	}
	return 0;
}