#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int maxn = 100 + 10;
const int INF = INT_MAX;

int matrix[maxn][maxn];	// 原矩阵
int total[maxn][maxn];	// 辅助矩阵
int arr[maxn];	// 一维数组		"降维"思想，将二维的矩阵最大和问题转化为一维的最大子序列和问题
int dp[maxn];
	
int MaxSubsequence(int n) {	// 实现了Kadane算法，用于求解一维数组的最大子序列和
	int maximum = -INF;
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			dp[i] = arr[i];
		}
		else {
			dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		}
		maximum = max(maximum, dp[i]);
	}
	return maximum;
}

int MaxSubmatrix(int n) {
	int maximal = -INF;
	for (int i = 0; i < n; ++i) {	// 枚举所有行组合
		for (int j = i; j < n; ++j) {
			for (int k = 0; k < n; ++k) {	// 获得一维数组
				if (i == 0) {
					arr[k] = total[j][k];
				}
				else {
					arr[k] = total[j][k] - total[i - 1][k];
				}
			}
			int current = MaxSubsequence(n);
			maximal = max(maximal, current);
		}
	}
	return maximal;
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &matrix[i][j]);
			}
		}
		for (int i = 0; i < n; ++i) {	// 初始化辅助函数
			for (int j = 0; j < n; ++j) {
				if (i == 0) {
					total[i][j] = matrix[i][j];
				}
				else {
					total[i][j] = total[i - 1][j] + matrix[i][j];	// total[i][j] 表示 第 j 列从第 0 行到第 i 行的累加和。
				}
			}
		}
		int answer = MaxSubmatrix(n);
		printf("%d\n", answer);
	}
	return 0;
}