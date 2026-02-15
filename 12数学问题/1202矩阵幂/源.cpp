#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

void MatrixMultiply(int m1[][11], int m2[][11], int res[][11], int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// res(i,j)=m1(i,0)*m2(0,j)+m1(i,1)*m2(1,j)+...+m1(i,n-1)*m2(n-1,j)		res的i行j列由m1的i行和m2的j列相乘得来
			res[i][j] = 0;
			for (int temp = 0; temp < n; ++temp) {
				res[i][j] += m1[i][temp] * m2[temp][j];
				// temp 循环是矩阵乘法的核心，它实现了行和列的点积计算。如果没有它，就无法正确计算矩阵乘法的结果。
				// 前两个循环（i 和 j）只是定位结果矩阵的位置，而 temp 循环才是真正完成计算的部分。
			}
		}
	}
}

void MatrixPower(int m1[][11], int res[][11], int n,int k) {
	if (k == 0) {	
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j) {
					res[i][j] = 1;
				}
				else {
					res[i][j] = 0;
				}
			}
		}
	}
	else if (k % 2 == 0) {
		int temp[11][11];
		MatrixPower(m1, temp,n,k/2);
		MatrixMultiply(temp, temp, res,n);
	}
	else {
		int temp1[11][11];
		MatrixPower(m1, temp1, n, k / 2);
		int temp2[11][11];
		MatrixMultiply(temp1, temp1, temp2, n);
		MatrixMultiply(temp2,m1, res, n);
	}
}
int main() {
	int matrix[11][11],n,k;
	while (scanf("%d%d", &n, &k) != EOF) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &matrix[i][j]);
			}
		}
		int res[11][11] = { 0 };
		MatrixPower(matrix, res, n, k);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (j == 0) {
					printf("%d", res[i][j]);
				}
				else {
					printf(" %d", res[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}