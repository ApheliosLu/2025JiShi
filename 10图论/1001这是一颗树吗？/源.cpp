#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

// 满足树的定义
// 1.入度：不存在入度大于2的结点
// 2.已连通的u，v加入一新边，成为环
// 3.边数=顶点数-1

// 并查集代码块
int father[10001];
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

int main() {
	int u, v;
	InitDisjointSet(10001);
	int edgeCount = 0;
	int vertexCount = 0;
	vector<int> vertex(10001);	// vectex[i]=0 -> 说明顶点i未出现过
	vector<int> inDegree(10001);	// 记录i的入读
	bool isOK = true;
	int caseIdx = 1;
	while (1) {
		scanf("%d%d", &u, &v);
		if (u == -1 && v == -1) {
			break;
		}
		else if (u == 0 && v == 0) {
			// 一个图的所有边已经记录完成

			// 判断是否是树
			if (vertexCount != edgeCount + 1) {
				isOK = false;
			}
			if (vertexCount == 0 && edgeCount == 0) {
				isOK = true;	// 空树的特例
			}
			if (isOK) {
				printf("Case %d is a tree.\n", caseIdx);
			}
			else {
				printf("Case %d is not a tree.\n", caseIdx);
			}

			// 重置代码块
			InitDisjointSet(10001);
			edgeCount = 0;
			vertexCount = 0;
			for (int i = 0; i < 10001; ++i) {
				vertex[i] = 0;
				inDegree[i] = 0;
			}
			isOK = true;
			++caseIdx;
		}
		else {
			// 往新图里加入新边
			++edgeCount;
			if (vertex[u] == 0) {
				vertex[u] = 1;
				++vertexCount;
			}
			if (vertex[v] == 0) {
				vertex[v] = 1;
				++vertexCount;
			}
			if (FindDisjointSet(u) == FindDisjointSet(v)) {	// 成环
				isOK = false;	
			}
			else {
				UnionDisjointSet(u, v);
			}
			++inDegree[v];
			if (inDegree[v] >= 2) {
				isOK = false;
			}
		}
	}

	return 0;
}