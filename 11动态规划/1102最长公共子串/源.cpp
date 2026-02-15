#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

short dp[10002][10002];

int main() {
	char s1[10001];
	char s2[10001];
	scanf("%s%s", s1, s2);
	int n = strlen(s1);
	int m = strlen(s2);
	for (int j = 0; j <= m; ++j) {	// 一方长度为零是，最长公共子串长度为零
		dp[0][j] = 0;
	}
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = 0;
	}
	short curmax = 0;	// 迭代生成最长公共子串
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s1[i - 1] >= 'a' && s1[i - 1] <= 'z' && s1[i - 1] == s2[j - 1]) {	// 右边缘是字母且相同
				dp[i][j] = dp[i - 1][j - 1] + 1;
				curmax = max(dp[i][j], curmax);	// 更新
			}
			else {	// 如果连不起来
				dp[i][j] = 0;
			}
		}
	}
	printf("%d\n", curmax);
	return 0;
}