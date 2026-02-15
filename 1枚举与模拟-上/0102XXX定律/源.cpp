#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int count = 0;
		while (n != 1) {
			if (n % 2 == 0) {
				n /= 2;
			}
			else {
				n = (n * 3 + 1) / 2;
			}
			++count;
		}
		printf("%d\n", count);
	}
	return 0;
}