#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

int father[1010];

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

int setCount;

void UnionDisjointSet(int u, int v) {	
	int uroot = FindDisjointSet(u);
	int vroot = FindDisjointSet(v);
	if (uroot != vroot) {	// 不是同一个集合
		--setCount;
	}
	father[vroot] = uroot;	
}

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (n == 0) {
			break;
		}
		InitDisjointSet(n + 1);	// 1~n
		setCount = n;	// 初始集合数量
		for (int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			UnionDisjointSet(u, v);
		}
		printf("%d\n", setCount - 1);
	}
}