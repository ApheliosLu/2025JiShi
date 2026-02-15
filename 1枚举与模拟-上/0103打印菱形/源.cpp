#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main() {
	char str[1000] = { 0 };
	char arr[100][100] = { 0 };	// 二维数组
	//int i;
	//for (i = 0; i < 10; i++) {
	//	str[i]=' ';
	//}
	//str[i] = '0';
	//printf("%s\n", str);
	//memset(str, 0, 1000);
	//for (i = 0; i < 8; i++) {
	//	str[i] = ' ';
	//}
	//for (int j = 0; j <= 1; j++) {
	//	str[i] = '0' + j;
	//	str[i + 1] = ' ';
	//	i += 2;
	//}
	//str[i] = '0';
	//printf("%s\n", str);
	int n;
	scanf_s("%d", &n);
	int i;
	for (i = 0; i <= n; i++) {
		int j;
		//memset(str, 0, 1000);	// 初始化
		for (j = 0; j < 2 * n - 2 * i; j++) {
			//arr[i][j] = ' ';
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
		memset(str, 0, 1000);
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