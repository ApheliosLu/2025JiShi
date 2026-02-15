#include<cstdio>
using namespace std;

int main() {
	int n;	// 输入整数个数
	int a;	// 保存每个数
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a);
		int count = 0;	// 统计约数个数
		for (int j = 1; j * j <= a; j++) {	// j用来试探是否是a的约数
			if (j * j == a) {
				++count;	// a是完全平方数
			}
			else if (a % j == 0) {
				count += 2;	// 一个j，一个a/j，两个约数
			}
		}
		printf("%d\n", count);
	}
	return 0;
}