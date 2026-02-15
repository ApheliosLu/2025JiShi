#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 1e6;
int father[MAXN];	// 父亲结点
int height[MAXN];	// 结点高度
bool visit[MAXN];	// 标记

void Initial(int n) {
	for (int i = 0; i < n; ++i) {
		father[i] = i;
		height[i] = 0;
	}
}

int Find(int x) {	// 查找根结点
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
int main() {
	Initial(MAXN);
	int x, y;
	while (scanf("%d%d", &x, &y) != EOF) {
		visit[x] = true;
		visit[y] = true;
		Union(x, y);	// 合并集合
	}
	int component = 0;	// 连通分量
	for (int i = 0; i < MAXN; ++i) {
		if (visit[i] && Find(i) == i) {		// 根节点的数量即为集合数目
			component++;
		}
	}
	printf("%d\n", component);
	return 0;
}