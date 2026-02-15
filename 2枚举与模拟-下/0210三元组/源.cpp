#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <map>
using namespace std;
int main() {
	int n, m;
	scanf("%d", &n);
	for (int idx = 0; idx < n; ++idx) {
		int arr[60] = { 0 };
		scanf("%d", &m);
		for (int i = 0; i < m; ++i) {
			scanf("%d", &arr[i]);
		}
		map<int, int> count; // arr_i + arr_j 作为key 出现次数作为value
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < m; ++j) {
				++count[arr[i] + arr[j]];
			}
		}
		int sum = 0;
		for (int i = 0; i < m; ++i) {
			sum += count[arr[i]];
		}

		printf("%d\n", sum);
	}


	return 0;
}
