#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

int father[1010];
// i数组下标是集合数据编号，father[i]是集合数据父亲的编号
// 根i father[i]和i相同

void InitDisjoinSet(int n) {
	// 0~n-1
	for (int i = 0; i < n; ++i) {
		father[i] = i;
	}
}

int FindDisjoinSet(int u) {
	if (u == father[u]) {
		return u;
	}
	else {
		father[u] = FindDisjoinSet(father[u]);
		return father[u];
	}
}

int setCount;	// 集合数

void UnionDisjoinSet(int u, int v) {
	int uroot = FindDisjoinSet(u);
	int vroot = FindDisjoinSet(v);
	if (uroot != vroot) {
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
		InitDisjoinSet(n + 1);	// 1~n
		setCount = n;	// 初始为n个集合
		for (int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			UnionDisjoinSet(u, v);
		}
		if (setCount == 1) {	// 通过最终集合数是否唯一来判断是否连通
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}