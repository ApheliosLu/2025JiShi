#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void ClockWiseRotate90(int matrix[10][10], int n) {
	// 顺时针旋转90度
	//1 2 3        7 4 1
	//4 5 6   -->  8 5 2
	//7 8 9        9 6 3

	// 当 n = 3 时 
	// 旋转前 --> 旋转后
	// 0,0 --> 0,2
	// 0,1 --> 1,2
	// 0,2 --> 2,2
	// 1,0 --> 0,1
	// 1,1 --> 1,1
	// 1,2 --> 2,1
	// ...
	// 规律就是
	// i,j --> j,n-1-i
	// 也可以写成
	// n-1-j,i --> i, j
	// 旋转其他度数重复执行该函数即可

	// 先备份一下矩阵
	int temp[10][10];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			temp[i][j] = matrix[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			matrix[i][j] = temp[n-1-j][i];
		}
	}
	return;
}

bool Compare(int lhs[10][10], int rhs[10][10], int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (lhs[i][j] != rhs[i][j]) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	/*
	//二维数组的地址
	int a[3][4] = {
		{1, 2, 3, 4},    // 第一行
		{5, 6, 7, 8},    // 第二行
		{9, 10, 11, 12}  // 第三行
	};
	cout << a << endl;			// 0x0000006C49CFF9C8	数组首元素的地址（即第一行的地址）
	cout << &a << endl;			// 0x0000006C49CFF9C8	整个数组的地址
	cout << a[0] << endl;		// 0x0000006C49CFF9C8	数组第一行的首元素地址（即 a[0][0] 的地址）
	cout << &a[0] << endl;		// 0x0000006C49CFF9C8	数组第一行的地址
	cout << a + 1 << endl;		// 0x0000006C49CFF9D8	跳过一行（即跳过 4 个整数），因此地址增加 4 * sizeof(int)
	cout << &a + 1 << endl;		// 0x0000006C49CFF9F8	跳过整个数组，因此地址增加 3 * 4 * sizeof(int)
	cout << a[0] + 1 << endl;	// 0x0000006C49CFF9CC	跳过第一个整数，因此地址增加 sizeof(int)
	cout << &a[0] + 1 << endl;	// 0x0000006C49CFF9D8	跳过一行（即跳过 4 个整数），因此地址增加 4 * sizeof(int)
	*/

	int n;
	int lhs[10][10];
	int rhs[10][10];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &lhs[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &rhs[i][j]);
		}
	}
	if (Compare(lhs, rhs, n)) {
		printf("0\n");
	}
	else {
		ClockWiseRotate90(lhs, n);
		if (Compare(lhs, rhs, n)) {
			printf("90\n");
		}
		else {
			ClockWiseRotate90(lhs, n);
			if(Compare(lhs, rhs, n)) {
				printf("180\n");
			}
			else {
				ClockWiseRotate90(lhs, n);
				if (Compare(lhs, rhs, n)) {
					printf("270\n");
				}
				else {
					printf("-1\n");
				}
			}
		}
	}
	return 0;
}