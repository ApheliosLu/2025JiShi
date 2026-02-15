#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
	int N,arr[100];
	while (scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; ++i) {
			scanf("%d", &arr[i]);
		}
		if (arr[0] != arr[1]) {
			printf("%d ",0);
		}
		for (int i = 1; i < N - 1; ++i) {
			if ((arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) || arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) {
				printf("%d ", i);
			}
		}
		if (arr[N - 2] != arr[N - 1]) {
			printf("%d ", N - 1);
		}
		printf("\n");
	}
	return 0;
}