#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 25;
int number[MAXN];

int main() {
	number[1] = 1;
	number[2] = 2;
	for (int i = 3; i < MAXN; ++i) {
		number[i] = number[i - 1] + number[i - 2];	// 若最后一步走1级，若最后一步走2级，
	}
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", number[n]);
	}
	return 0;
}