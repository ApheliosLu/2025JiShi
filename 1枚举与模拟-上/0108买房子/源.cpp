#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main() {
	int N, K;
	while (scanf("%d%d", &N, &K) != EOF) {
		bool canBuy = false;
		double housePrize = 200;
		double totalMoney = N;

		for (int i = 1; i <= 21; i++) {
			if (totalMoney >= housePrize) {
				printf("%d\n", i);
				canBuy = true;
				break;
			}
			totalMoney += N;
			housePrize = housePrize * (1 + K / 100.0);
		}
		if (canBuy == false) {
			printf("Impossible\n");
		}
	}
	return 0;
}