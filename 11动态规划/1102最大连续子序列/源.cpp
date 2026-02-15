#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int MAXN = 1e4 + 10;
const int INF = INT_MAX;

int arr[MAXN];
int dp[MAXN];

//  Kadane Ëã·¨
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		int maximum = -INF;
		int start, last;
		int head, tail;
		for(int i=0;i<n;++i){
			if (i == 0 || dp[i - 1] < 0) {
				dp[i] = arr[i];
				start = arr[i];
				last = arr[i];
			}
			else {
				dp[i] = dp[i - 1] + arr[i];
				last = arr[i];
			}
			if (maximum < dp[i]) {
				maximum = dp[i];
				head = start;
				tail = last;
			}
		}
		if (maximum < 0) {
			maximum = 0;
			head = arr[0];
			tail = arr[n - 1];
		}
		printf("%d %d %d\n", maximum, head, tail);
	}
	return 0;
}