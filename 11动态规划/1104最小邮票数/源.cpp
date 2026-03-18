#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

int INF = 0x7f7f7f7f;

int dp[110];
int weight[30];

int main() {
	int n, m;
	while (scanf("%d%d", &m, &n) != EOF) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &weight[i]);
		}
		for (int i = 1; i <= m; ++i) {
			dp[i] = INF;
		}
		dp[0] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = m; j >= weight[i]; --j) {
				dp[j] = min(dp[j], dp[j - weight[i]] + 1);	// dp[j] 表示凑成总重量恰好为 j 所需的最少物品个数
			}
		}
		if (dp[m] == INF) {
			printf("%d\n", 0);
		}
		else {
			printf("%d\n", dp[m]);
		}
	}
	return 0;
}