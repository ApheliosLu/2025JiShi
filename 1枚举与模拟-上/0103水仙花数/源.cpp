#include<cstdio>
using namespace std;

int main() {
	int m, n;
	while (1) {
		scanf_s("%d%d", &m, &n);
		if (m == 0 && n == 0) {
			break;
		}
		int count = 0;	// 统计水仙花数的个数
		for (int i = m; i <= n; ++i) {	// i用于枚举是否是水仙花数
			int units = i % 10;	// 个位
			int tens = (i / 10) % 10;	// 十位
			int hundreds = i / 100;	// 百位
			if (units * units * units + tens * tens * tens + hundreds * hundreds * hundreds == i) {
				++count;
				printf("%d ", i);
			}
		}
		if (count == 0) {
			printf("no\n");
		}
		else {
			printf("\n");
		}
	}
	return 0;
}