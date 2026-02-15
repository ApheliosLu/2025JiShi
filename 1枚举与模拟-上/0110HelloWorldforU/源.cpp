#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main() {
	char str[1024];
	char pattern[30][30] = { 0 };
	while (scanf("%s", str) != EOF) {
		int N = strlen(str);
		int n1, n2, n3;
		// 枚举算出n1、n2、n3的合理值
		for (n2 = 3; n2 <= N; ++n2) {
			// n1=(N+2-n2)/2
			if ((N + 2 - n2) % 2 == 0) {
				n1 = (N + 2 - n2) / 2;
				if (n1 <= n2) {
					n3 = n1;
					break;
				}
			}
		}
		for (int i = 0; i < 29; ++i) {
			for (int j = 0; j < 29; ++j) {
				pattern[i][j] = ' ';
			}
		}
		int x=0, y = 0;
		for (int i = 0; i < N; ++i) {
			if (i < n1 - 1) {	// 向下
				pattern[x][y] = str[i];
				++x;
			}
			else if (i < n1 + n2 - 2) {	// 向右
				pattern[x][y] = str[i];
				++y;
			}
			else {
				pattern[x][y] = str[i];
				--x;
			}
		}
		for (int i = 0; i < n1; ++i) {
			printf("%s\n", pattern[i]);
		}
	}
	return 0;
}
