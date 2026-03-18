#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int dp[13][13] = { 0 };	// 二维数组dp[M][N]表示M个苹果放入N个盘子
	int M, N;
	while (scanf("%d%d", &M, &N) != EOF) {
		memset(dp, 0, sizeof(dp));  // sizeof(dp) 会计算整个二维数组的字节数
		for (int i = 0; i <= M; ++i) {
			dp[i][1] = 1;	// 仅有一个盘子
		}
		for (int i = 1; i <= N; ++i)
		{
			dp[1][i] = 1;	// 仅有一个苹果
			dp[0][i] = 1;	// 没有苹果
		}
		for (int i = 2; i <= M; ++i) { // 遍历苹果数量
			for (int j = 2; j <= N; ++j) {	// 遍历盘子数量
				if (i >= j) {	// 如果苹果数量比盘子数量大
					dp[i][j] = dp[i][j - 1] + dp[i - j][j];	//至少有一个盘子为空 和 所有盘子都不为空 
				}
				else {
					dp[i][j] = dp[i][i];
				}
			}
		}
		printf("%d\n", dp[M][N]);
	}
	return 0;
}