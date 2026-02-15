#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &vec[i]);
	}
	sort(vec.begin(), vec.end());
	if (n == 1) {
		printf("%d\n-1\n", vec[0]);
	}
	else {
		printf("%d\n", *(vec.end() - 1));
		for (int i = 0; i < vec.size() - 1; ++i) {
			printf("%d ", vec[i]);
		}
		printf("\n");
	}

	return 0;
}