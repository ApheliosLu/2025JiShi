#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1002][1002];
// dp[i][j] 指s1的前i个元素 s2的前j个元素的最大公共长度

int main() {
	int n, m;
	char s1[1001];
	char s2[1001];
	scanf("%d%d", &n, &m);
	scanf("%s%s", s1, s2);

	for (int j = 0; j <= m; ++j) {
		dp[0][j] = 0;	// s1为空的情况 
	}
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = 0;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			// s1[0]~s1[i-1] 和 s2[0]~s2[j-1]
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j]=max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	printf("%d\n", dp[n][m]);
	return 0;
}