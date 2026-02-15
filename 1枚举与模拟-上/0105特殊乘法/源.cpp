#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;

int main() {
	char lhs[20];
	char rhs[20];
	while (scanf("%s%s", lhs, rhs) != EOF) {
		int sum = 0;
		for (int i = 0; lhs[i] != '\0'; ++i) {
			for (int j = 0; rhs[j] != '\0'; ++j) {
				sum = sum + (lhs[i] - '0') * (rhs[j] - '0');	// 将字符数字转换为对应的整数值
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}