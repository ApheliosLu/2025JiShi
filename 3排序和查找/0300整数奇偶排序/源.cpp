#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int lhs, int rhs) {
	if (lhs % 2 == 1 && rhs % 2 == 0) {
		return true;	// 不交换
	}
	else if (lhs % 2 == 1 && rhs % 2 == 1 && lhs > rhs) {
		return true;	// 不交换
	}
	else if (lhs % 2 == 0 && rhs % 2 == 0 && lhs < rhs) {
		return true;	// 不交换
	}
	else {
		return false;	// 交换
	}
}

int main() {
	int arr[10];
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &arr[i]);	// &arr[i]等价于arr+i
	}
	sort(arr, arr + 10, compare);
	for (int i = 0; i < 10; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}