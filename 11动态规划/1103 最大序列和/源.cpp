#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

long long s[1000001];	// -10^9 ~ 10^9
long long dp[1000001];	// dp[i] 代表前i个元素 必须包含右边缘 的最大子序列和
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &s[i]);
	}
	dp[1] = s[0];
	long long curmax = dp[1];
	for (int i = 2; i <= n; ++i) {
		if (dp[i - 1] <= 0) {
			dp[i] = s[i - 1];	// 只保留最后一项
		}
		else {
			dp[i] = dp[i - 1] + s[i - 1];	// 更新
		}
		curmax = max(dp[i], curmax);
	}
	printf("%lld\n", curmax);
	return 0;
}