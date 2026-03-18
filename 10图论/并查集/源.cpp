#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

int father[1000];
// i/数组下标是集合数据编号    father[i] 保存集合数据父亲的编号
// 根i father[i]和i相同

void InitDisjointSet(int n) {	// 初始化
	// 0~n-1
	for (int i = 0; i < n; ++i) {
		father[i] = i;
	}
}

int FindDisjointSet(int u) {	// 查找根
	if (u == father[u]) {
		return u;	// 本身是根
	}
	else {
		father[u] = FindDisjointSet(father[u]);	// 递归查找根并修改
		return father[u];
	}
}

int UnionDisjointSet(int u, int v) {	// 合并
	int uroot = FindDisjointSet(u);
	int vroot = FindDisjointSet(v);
	father[vroot] = uroot;	// 不再是根
	return 0;
}

int main() {
	// 1234
	// 567
	// 08
	int n = 9;
	InitDisjointSet(n);
	UnionDisjointSet(1, 2);
	UnionDisjointSet(1, 3);
	UnionDisjointSet(1, 4);
	UnionDisjointSet(5, 6);
	UnionDisjointSet(5, 7);
	UnionDisjointSet(0, 8);
	for (int i = 0; i < 9; ++i) {
		printf("NO = %d, root = %d\n", i, FindDisjointSet(i));
	}
	return 0;
}