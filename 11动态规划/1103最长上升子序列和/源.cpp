#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 1000 + 10;

int arr[MAXN];
int dp[MAXN];

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		int answer = 0;
		for (int i = 0; i < n; ++i) {
			dp[i] = arr[i];		// 初始化为arr[i]
			for (int j = 0; j < i; ++j) {
				if (arr[j] < arr[i]) {	// 保证升序子序列
					dp[i] = max(dp[i], dp[j] + arr[i]);
				}
			}
			answer = max(answer, dp[i]);
		}
		printf("%d\n", answer);
	}
	return 0;
}