#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<cstring>
using namespace std;

void Square(int curSize, int patSize, char pattern[3000][3000], char picture[3000][3000], char last[3000][3000]) {
	if (curSize == 1) {
		for (int i = 0; i < patSize; ++i) {
			for (int j = 0; j < patSize; ++j) {
				picture[i][j] = pattern[i][j];
			}
		}
	}
	else {
		// 根据模板的字符是否为空格进行分行处理
		for (int i = 0; i < patSize; ++i) {
			for (int j = 0; j < patSize; ++j) {
				if (pattern[i][j] == ' ') {
					for (int pi = i * curSize; pi < i * curSize + curSize; ++pi) {	// 模板中的一个字符 pattern[i][j] 对应 picture 中的一个 curSize x curSize 的区域
						for (int pj = j * curSize; pj < j * curSize + curSize; ++pj) {
							picture[pi][pj] = ' ';
						}
					}
				}
				else {
					// 建立新图案和模板的下标映射关系
					for (int pi = i * curSize; pi < i * curSize + curSize; ++pi) {
						for (int pj = j * curSize; pj < j * curSize + curSize; ++pj) {
							picture[pi][pj] = last[pi - i * curSize][pj - j * curSize];
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < curSize * patSize; ++i) {
		for (int j = 0; j < curSize * patSize; ++j) {
			last[i][j] = picture[i][j];	// 将当前生成的 picture 复制到 last 中，以便在下一次递归中使用。
		}
	}
}

// 数组的大小为 3000*3000 约9MB，超过了1MB的限制，所以这里设成全局变量 
char pattern[3000][3000];
char last[3000][3000];
char picture[3000][3000];

int main() {
	int N, Q;
	while (1) {
		scanf("%d", &N);
		if (N == 0) {
			break;
		}
		getchar();	// fgets会读到'\n' 所以先用getchar读掉'\n'
		for (int i = 0; i < N; ++i) {
			fgets(pattern[i], 3000, stdin);
			int curLength = strlen(pattern[i]);	// n --> 3
			for (int j = curLength-1; j < N; ++j) {
				pattern[i][j] = ' ';
			}
		}
		scanf("%d", &Q);
		int curSize = 1;
		// 逐渐分形操作
		for (int i = 0; i < Q; ++i) {
			Square(curSize, N, pattern, picture, last);
			curSize *= N;
		}

		for (int i = 0; i < curSize; ++i) {
			for (int j = 0; j < curSize; ++j) {
				printf("%c", picture[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}