//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//#include<cstring>
//using namespace std;
//
//void Square(int curSize, int patSize, char pattern[3000][3000], char picture[3000][3000], char last[3000][3000]) {
//	if (curSize == 1) {
//		for (int i = 0; i < patSize; ++i) {
//			for (int j = 0; j < patSize; ++j) {
//				picture[i][j] = pattern[i][j];
//			}
//		}
//	}
//	else {
//		// 根据模板的字符是否为空格进行分行处理
//		for (int i = 0; i < patSize; ++i) {
//			for (int j = 0; j < patSize; ++j) {
//				if (pattern[i][j] == ' ') {
//					for (int pi = i * curSize; pi < i * curSize + curSize; ++pi) {	// 模板中的一个字符 pattern[i][j] 对应 picture 中的一个 curSize x curSize 的区域
//						for (int pj = j * curSize; pj < j * curSize + curSize; ++pj) {
//							picture[pi][pj] = ' ';
//						}
//					}
//				}
//				else {
//					// 建立新图案和模板的下标映射关系
//					for (int pi = i * curSize; pi < i * curSize + curSize; ++pi) {
//						for (int pj = j * curSize; pj < j * curSize + curSize; ++pj) {
//							picture[pi][pj] = last[pi - i * curSize][pj - j * curSize];
//						}
//					}
//				}
//			}
//		}
//	}
//	for (int i = 0; i < curSize * patSize; ++i) {
//		for (int j = 0; j < curSize * patSize; ++j) {
//			last[i][j] = picture[i][j];	// 将当前生成的 picture 复制到 last 中，以便在下一次递归中使用。
//		}
//	}
//}
//
//// 数组的大小为 3000*3000 约9MB，超过了1MB的限制，所以这里设成全局变量 
//char pattern[3000][3000];	// 最初传入的模板
//char last[3000][3000];		// 
//char picture[3000][3000];
//
//int main() {
//	int N, Q;
//	while (1) {
//		scanf("%d", &N);
//		if (N == 0) {
//			break;
//		}
//		getchar();	// fgets会读到'\n' 所以先用getchar读掉'\n'
//		for (int i = 0; i < N; ++i) {
//			fgets(pattern[i], 3000, stdin);
//			int curLength = strlen(pattern[i]);	// n --> 3		curLength为pattern每一行的长度
//			for (int j = curLength-1; j < N; ++j) {
//				pattern[i][j] = ' ';
//			}
//		}
//		scanf("%d", &Q);
//		int curSize = 1;
//		// 逐渐分形操作
//		for (int i = 0; i < Q; ++i) {
//			Square(curSize, N, pattern, picture, last);
//			curSize *= N;
//		}
//
//		for (int i = 0; i < curSize; ++i) {
//			for (int j = 0; j < curSize; ++j) {
//				printf("%c", picture[i][j]);
//			}
//			printf("\n");
//		}
//	}
//
//	return 0;
//}


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 递归绘制第 level 级图形，左上角坐标为 (r, c)
void draw(int level, int r, int c,
		  const vector<string>& pattern, int N,
		  const vector<int>& sizeLevel, vector<string>& out) {
	if (level == 1) {
		// 直接复制模板
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				out[r + i][c + j] = pattern[i][j];
			}
		}
	} else {
		int sub = sizeLevel[level - 1];          // 低一级图形的尺寸
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (pattern[i][j] != ' ') {      // 只有非空格才递归
					draw(level - 1, r + i * sub, c + j * sub,
						 pattern, N, sizeLevel, out);
				}
				// 空格区域保持空白（已经初始化为空格）
			}
		}
	}
}

int main() {
	int N;
	while (cin >> N && N != 0) {
		cin.ignore();                       // 忽略 N 后面的换行符
		vector<string> pattern(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, pattern[i]);
			// 去除可能存在的 Windows 换行符 '\r'
			if (!pattern[i].empty() && pattern[i].back() == '\r') {
				pattern[i].pop_back();
			}
		}

		int Q;
		cin >> Q;

		// 预计算各级尺寸：sizeLevel[k] = N^k, 其中 sizeLevel[0] = 1
		vector<int> sizeLevel(Q + 1);
		sizeLevel[0] = 1;
		for (int i = 1; i <= Q; ++i) {
			sizeLevel[i] = sizeLevel[i - 1] * N;
		}

		int totalSize = sizeLevel[Q];
		vector<string> result(totalSize, string(totalSize, ' '));

		draw(Q, 0, 0, pattern, N, sizeLevel, result);

		// 输出结果
		for (const auto& line : result) {
			cout << line << '\n';
		}
		// 相邻两组数据之间不加空行（与样例一致）
	}
	return 0;
}