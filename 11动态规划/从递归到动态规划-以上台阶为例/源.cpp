#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//int f(int n) {
//	if (n == 1) {
//		return 1;
//	}
//	else if (n == 2) {
//		return 2;
//	}
//	else {
//		return f(n - 1) + f(n - 2);
//	}
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	printf("%d\n", f(n));
//	return 0;
//}

int main() {
	int dp[16] = { 0 };		// 记录中间状态
	// dp[i] 代表 到第i级台阶的方案数
	dp[1] = 1;
	dp[2] = 2;
	int n;
	scanf("%d", &n);
	for (int i = 3; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%d\n", dp[n]);
	return 0;
}