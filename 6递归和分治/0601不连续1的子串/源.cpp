#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int f0(int n);	// 提前声明
int f1(int n);
int f0(int n) {	// 末尾为0
	if (n == 1) {
		return 1;
	}
	else {
		return f0(n - 1) + f1(n - 1);
	}
}
int f1(int n) {	// 末尾为1
	if (n == 1) {
		return 1;
	}
	else {
		return f0(n - 1);
	}
}
int main() {
	// 分治 分类 
	int n;
	scanf("%d", &n);
	printf("%d\n", f0(n) + f1(n));
	return 0;
}