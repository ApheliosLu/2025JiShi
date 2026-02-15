#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	vector<int> prime;
	vector<int> num(32001);
	// 求出2~32000范围内的所有质数
	// 因为32000*32000>10^9，假如一个数不是质数且小于10^9，它必然存在一个质因子小于32000
	for (int i = 2; i <= 32000; ++i) {
		if (num[i] == 0) {
			prime.push_back(i);	// prime内存储了所有质数
		}
		for (int j = 2 * i; j <= 32000; j += i) {
			num[j] = 1;
		}
	}
	int lastIndex = prime.size() - 1;

	int N;
	while (scanf("%d", &N) != EOF) {
		int count = 0;
		for (int i = 0; i <= lastIndex && prime[i] <= N;) {
			if (N % prime[i] == 0) {	// 找到了其中一个质因子
				N /= prime[i];
				++count;
			}
			else {
				++i;
				if (i > lastIndex) {
					// 剩下的数 比 32000范围内最大的质数还大
					// 剩下的数 就是一个 特别大的质数因子
					++count;	// 额外再加一个因子 数N本身是一个大质数
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}