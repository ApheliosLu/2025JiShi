#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main() {
	char str[1000] = { 0 };
	char arr[100][100] = { 0 };	// 二维数组


	/*int i;
	for (i = 0; i < 10; i++) {
		str[i]=' ';
	}
	str[i] = '0';
	printf("%s\n", str);

	memset(str, 0, 1000);
	for (i = 0; i < 8; i++) {
		str[i] = ' ';
	}
	for (int j = 0; j <= 1; j++) {
		str[i] = '0' + j;
		str[i + 1] = ' ';
		i += 2;
	}
	str[i] = '0';
	printf("%s\n", str);*/


	int n;
	scanf_s("%d", &n);
	int i;
	for (i = 0; i <= n; i++) {
		int j;
		//memset(str, 0, 1000);	// 初始化
		for (j = 0; j < 2 * n - 2 * i; j++) {
			arr[i][j] = ' '; 
		}
		for (int k = 0; k <= i; k++) {
			arr[i][j] = '0' + k;
			arr[i][j+1] = ' ';
			j += 2;
		}
		for (int k = i - 1; k >= 0; k--) {
			arr[i][j] = '0' + k;
			arr[i][j+1] = ' ';
			j += 2;
		}
		//printf("%s\n", str);
	}
	for (i = n + 1; i <= 2 * n; i++) {
		int j;
		//memset(str, 0, 1000);
		for (j = 0; j < 2 * i - 2 * n; j++) {
			arr[i][j] = ' ';
		}
		for (int k = 0; k <= 2*n-i; k++) {
			arr[i][j] = '0' + k;
			arr[i][j+1] = ' ';
			j += 2;
		}
		for (int k = 2*n-i - 1; k >= 0; k--) {
			arr[i][j] = '0' + k;
			arr[i][j+1] = ' ';
			j += 2;
		}
		//printf("%s\n", str);
	}
	for (int i = 0; i < 2 * n + 1; i++) {
		printf("%s\n", arr[i]);
	}
	return 0;
}

//#include <iostream>
//#include <cmath>   // 用于abs函数
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;  // 输入中心数字
//
//	// 总行数为 2*n + 1，i 从 0 到 2*n
//	for (int i = 0; i <= 2 * n; ++i) {
//		int maxDigit = n - abs(i - n);        // 当前行的最大数字
//		int spaces = 2 * abs(i - n);          // 前导空格数量（每个空格占一位）
//
//		// 输出前导空格
//		for (int s = 0; s < spaces; ++s) {
//			cout << ' ';
//		}
//
//		// 递增输出从0到maxDigit
//		for (int d = 0; d <= maxDigit; ++d) {
//			cout << d << ' ';
//		}
//
//		// 递减输出从maxDigit-1到0
//		for (int d = maxDigit - 1; d >= 0; --d) {
//			cout << d << ' ';
//		}
//
//		cout << endl;  // 换行
//	}
//
//	return 0;
//}