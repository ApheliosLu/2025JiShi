#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<stdlib.h>
using namespace std;

int main() {
    int a0, a1, p, q, k;
    while (scanf("%d %d %d %d %d", &a0, &a1, &p, &q, &k) != EOF) {
		int* a = (int*)calloc(k + 1, sizeof(int));  // ∂ØÃ¨∑÷≈‰ø’º‰
        a[0] = a0, a[1] = a1;
        for (int i = 2; i <= k; i++)
            a[i] = (p * a[i - 1] + q * a[i - 2]) % 10000;
        printf("%d\n", a[k]);
    }
	return 0;
}
