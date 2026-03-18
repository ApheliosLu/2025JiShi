#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int c, n;
	scanf("%d%d",&c, &n);
	int p[101];
	int v[101];
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p[i], &v[i]);
	}
	int dp[1001][102];	// dp[x][y]表示 在总额度不超过x块的情况下，考察0~y-1号商品的最大评分
	for (int y = 0; y <= n; ++y) {	// 边界情况1和2
		dp[0][y] = 0;	// 没有额度
	}
	for (int x = 0; x <= c; ++x) {
		dp[x][0]=0;		// 没有商品 同样没有评分
	}
	for (int x = 1; x <= c; ++x) {
		for (int y = 1; y <= n; ++y) {
			if (x - p[y - 1] < 0) {
				dp[x][y] = dp[x][y - 1];	// 额度不足以支付最后一个y-1号商品
			}
			else {
				dp[x][y]=max(dp[x][y - 1], dp[x - p[y - 1]][y - 1] + v[y - 1]);	// 对比不买y-1号商品和买y-1号商品的价值
			}
		}
	}
	printf("%d\n", dp[c][n]);
	return 0;
}