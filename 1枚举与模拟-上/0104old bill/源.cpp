#include<cstdio>
using namespace std;

int main() {
	int N, X, Y, Z;
	int total;
	// N*price=aXYZb
	while (scanf_s("%d%d%d%d", &N, &X, &Y, &Z) != EOF) {
		int flag = 0;	// 记录是否存在合法解
		for (int a = 9; a > 0; a--) {
			for (int b = 9; b >= 0; b--) {
				total = 10000 * a + 1000 * X + 100 * Y + 10 * Z + b;
				if (total % N == 0) {
					printf("%d %d %d", a, b, total / N);
					flag = 1;
				}
				if (flag == 1) {
					break;
				}
			}
			if (flag == 1) {
				break;
			}
		}	// flag用来跳出多重循环
		if (flag == 0) {
			printf("0\n");
		}
	}
}