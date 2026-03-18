#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int f(int n) {	// 获取斐波那契数列数列各项值
	if (n == 0 || n == 1) {
		return n;
	}
	else {
		return f(n - 1) + f(n - 2);
	}
}

int Fibonacci[] = {
	1,
	2,
	3,
	5,
	8,
	13,
	21,
	34,
	55,
	89,
	144,
	233,
	377,
	610,
	987,
	1597,
	2584,
	4181,
	6765,
	10946,
	17711,
	28657,
	46368,
	75025,
	121393,
	196418,
	317811,
	514229,
	832040,
	1346269,
	2178309,
	3524578,
	5702887,
	9227465,
	14930352,
	24157817,
	39088169,
	63245986,
};


// 生成斐波那契数列
vector<int> generateFibonacci(int n) {
	vector<int> fib;
	if (n >= 1) fib.push_back(1);  // F[0] = 1
	if (n >= 2) fib.push_back(2);  // F[1] = 2
	for (int i = 2; i < n; ++i) {
		fib.push_back(fib[i - 1] + fib[i - 2]);
	}
	return fib;
}
// 生成斐波那契前缀和数组
vector<int> generateFibonacciSums(const vector<int>& fib) {
	vector<int> sums;
	if (fib.empty()) return sums;

	sums.push_back(fib[0]);  // 第一个和就是F[0]
	for (int i = 1; i < fib.size(); ++i) {
		sums.push_back(sums.back() + fib[i]);
	}
	return sums;
}

int sum[] = {	// 这个数组存储了斐波那契数列的前缀和，即sum[i] = F[0] + F[1] + ... + F[i]。
		1, // F[0]
		3, // F[0] + F[1]
		6, // F[0] + F[1] + F[2]
		11,
		19,
		32,
		53,
		87,
		142,
		231,
		375,
		608,
		985,
		1595,
		2582,
		4179,
		6763,
		10944,
		17709,
		28655,
		46366,
		75023,
		121391,
		196416,
		317809,
		514227,
		832038,
		1346267,
		2178307,
		3524576,
		5702885,
		9227463,
		14930350,
		24157815,
		39088167,
		63245984,
		102334153,
		165580139
};
int DFS(int n, int beg) {
	int result = 0;
	if (n > sum[beg]) {
		return 0;
	}
	for(int i = beg; i >= 0; --i) {
		if (n - Fibonacci[i] == 0) {
			result += 1;
		}
		else if (n - Fibonacci[i] > 0) {
			result += DFS(n - Fibonacci[i], i - 1);
		}
	}
	return result;
}
int main() {
	/*for (int i = 1; i < 40; ++i) {
		printf("%d,\n", f(i));
	}*/
	int n;
	scanf("%d", &n);
	printf("%d\n", DFS(n, 37));
	return 0;
}