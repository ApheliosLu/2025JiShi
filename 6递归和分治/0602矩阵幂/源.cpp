#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void MatrixMultiply(int m1[11][11], int m2[11][11], int res[11][11], int  n) {	// 计算两个矩阵的乘积
	for(int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			res[i][j] = 0;
			// a00*b00+a01*b10+a02*b20
			for (int k = 0; k < n; ++k) {
				res[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}
void MatrixPower(int m1[11][11], int res[11][11], int n, int k) {
	if (k == 1) {	// 一次幂即为自身
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				res[i][j] = m1[i][j];
			}
		}
	}
	else if (k % 2 == 0) {	// 偶数次幂
		int temp[11][11];
		MatrixPower(m1, temp, n, k / 2);	// 先获得k/2次幂即temp
		MatrixMultiply(temp, temp, res, n);	// 当k是偶数时，A^k = (A^(k/2)) × (A^(k/2))

	}
	else {	// 奇数次幂 A^k = A × (A^((k-1)/2)) × (A^((k-1)/2))
		int temp1[11][11];
		int temp2[11][11];
		MatrixPower(m1, temp1, n, k / 2);	// 获取（k-1）/2次
		MatrixMultiply(temp1, temp1, temp2, n);		// (A^((k-1)/2)) × (A^((k-1)/2))
		MatrixMultiply(temp2, m1, res, n);	// 再乘一次m1
	}

}
int main() {
	int matrix[11][11];
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &matrix[i][j]);
		}
	}
	int res[11][11];	// 最终结果
	MatrixPower(matrix, res, n, k);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}