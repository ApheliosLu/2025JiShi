#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main() {
	int n;
	char in, out;
	// %d %lf .. 忽略空格
	// %c 不忽略空格
	char pattern[100][100] = { 0 };
	while (scanf("%d %c %c", &n, &in, &out) != EOF) {
		int layer;	// 层级 0 -> n/2	
		// 中心点坐标为 (n/2, n/2)
		// 第 layer 层（0为最内层），
		// 该层矩形的左上角坐标为(n / 2 - layer, n / 2 - layer)，
		// 右下角坐标为(n / 2 + layer, n / 2 + layer)。
		// 即矩形覆盖从第 n / 2 - layer 行到第 n / 2 + layer 行，从第 n / 2 - layer 列到第 n / 2 + layer 列的区域。
		memset(pattern, 0,sizeof(pattern));

		char current = in;	//  当前层级的花色
		for (layer = 0; layer <= n / 2; ++layer) {
			// n/2-layer,n/2-layer 左上
			// n/2-layer,n/2+layer 右上
			// n/2+layer,n/2-layer 左下
			// n/2+layer,n/2+layer 右下
			for (int x = n / 2 - layer, y = n / 2 - layer; y <= n / 2 + layer; ++y) {	// 左上到右上
				pattern[x][y] = current;
			}
			for (int x = n / 2 + layer, y = n / 2 - layer; y <= n / 2 + layer; ++y) {	// 左下到右下
				pattern[x][y] = current;
			}
			for (int x = n / 2 - layer, y = n / 2 - layer; x <= n / 2 + layer; ++x) {	// 左上到左下
				pattern[x][y] = current;
			}
			for (int x = n / 2 - layer, y = n / 2 + layer; x <= n / 2 + layer; ++x) {	// 右上到右下
				pattern[x][y] = current;
			}

			if (in == current) {
				current = out;
			}
			else{
				current = in;
			}
		}
		if (n > 1) {
			pattern[0][0] = ' ';
			pattern[0][n - 1] = ' ';
			pattern[n - 1][0] = ' ';
			pattern[n - 1][n - 1] = ' ';
		}
		for (int i = 0; i < n; ++i) {
			printf("%s\n", pattern[i]);
		}
	}
	return 0;
}