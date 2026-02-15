#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> vec(n);
	int dp[50][30] = { 0 };
	// dp[i][j] 表示用i元买前j种（0~j-1）商品的方案数
	for (int i = 0; i < n; ++i) {
		scanf("%d", &vec[i]);
	}
	for (int i = 0; i < n; ++i) {
		dp[i][0] = 0;	// 无论多少钱，没有商品则方案数为0
	}
	for (int j = 0; j < n; ++j) {
		dp[0][j] = 0;	// 无论多少商品，没有钱则方案数为0
	}
	for (int i = 1; i <= 40; ++i) {
		for (int j = 1; j <= n; ++j) {
			// 如果i<vec[j-1] 则只能不选择vec[j-1]商品
			// 如果i>=vec[j-1] 则可选可不选
			if (i < vec[j - 1]) {
				dp[i][j] = dp[i][j - 1];
			}
			else if (i == vec[j - 1]) {	// 选择vec[j-1]后剩余0元，故只有一种方案
				dp[i][j] = dp[i][j - 1] + 1;
			}
			else {
				dp[i][j] = dp[i][j - 1] + dp[i - vec[j - 1]][j - 1];
			}
		}
	}
	printf("%d\n", dp[40][n]);
	return 0;
}