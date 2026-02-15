#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &vec[i]);
	}
	// 某对i,j vec[i]-vec[j]=x -> vec[i]=vec[j]+x
	unordered_map<int, long long> diffCount;
	for (int j = 0; j < n; ++j) {
		++diffCount[vec[j] + x];	// key为vec[j]+x value为出现次数
	}
	long long count = 0;
	for (int i = 0; i < n; ++i) {
		count += diffCount[vec[i]];
	}
	printf("%lld\n", count);
	return 0;
}