#include<cstdio>
using namespace std;

int main() {
	int n;	// n的范围为1到99
	int ans = 0;	// 与7无关的数的平方和
	while (scanf_s("%d", &n) != EOF) {
		ans = 0;
		for (int i = 0; i <= n; i++) {
			if (i % 7 == 0	// 被7整除
				|| i / 10 == 7	// 十位是7
				|| i % 10 == 7	// 个位是7
				) {
				continue;
			}
			else {
				ans += i * i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}