#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int dp[10001] = { 1,1,2 };
	int n;
	scanf("%d", &n);
	for (int i = 3; i <= n; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 999983;	
		// 如果最后一列是垂直放置的 2×1 骨牌，那么前面的部分是 2×(n-1) 的地板，铺法是 f(n-1)。
		// 如果最后两列是水平放置的两个 1×2 骨牌（上下各一个），那么前面的部分是 2×(n - 2) 的地板，铺法是 f(n - 2)。
	}
	printf("%d\n", dp[n]);
	return 0;
}