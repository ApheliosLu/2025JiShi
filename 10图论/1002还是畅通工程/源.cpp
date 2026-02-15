// 最小生成树 Kruskal算法的基本实现
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 并查集代码块
int father[1000];
void InitDisjointSet(int n) {
	for (int i = 0; i < n; ++i) {
		father[i] = i;
	}
}
int FindDisjointSet(int u) {
	if (u == father[u]) {
		return u;
	}
	else {
		father[u] = FindDisjointSet(father[u]);
		return father[u];
	}
}
int UnionDisjointSet(int u, int v) {
	int uroot = FindDisjointSet(u);
	int vroot = FindDisjointSet(v);
	father[vroot] = uroot;
	return 0;
}

struct Edge {
	int u;
	int v;
	int weight;
	Edge(int _u,int _v,int _weight) {	// 构造函数 特点：在类内，无返回值，名称与类名相同
		u = _u;
		v = _v;
		weight = _weight;
	}
};

bool compare(Edge lhs, Edge rhs) {
	return lhs.weight < rhs.weight;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) {
			break;
		}
		vector<Edge> edgeVec;
		InitDisjointSet(n + 1);
		for (int i = 0; i < (n - 1) * n / 2; ++i) {	// 加入边
			int u, v, weight;
			scanf("%d%d%d", &u, &v, &weight);
			//Edge e;	可以用类的构造函数简化
			//e.u = u;
			//e.v = v;
			//e.weight = weight;
			Edge e(u, v, weight);	// 构造函数
			edgeVec.push_back(e);
		}

		// kruskal 算法实现
		
		// 1.排序
		sort(edgeVec.begin(), edgeVec.end(), compare);

		// 2. 遍历edgeVec 加入子图
		int totalWeight = 0;
		int curEdgeNum = 0;
		for (int i = 0; i < edgeVec.size(); ++i) {
			int u = edgeVec[i].u;
			int v = edgeVec[i].v;
			int weight = edgeVec[i].weight;
			if (FindDisjointSet(u) != FindDisjointSet(v)) {
				UnionDisjointSet(u, v);
				++curEdgeNum;
				totalWeight += weight;

				// 3.边数=顶点数-1
				if (curEdgeNum == n - 1) {
					break;
				}
			}
		}
		printf("%d\n", totalWeight);
	}
	return 0;
}