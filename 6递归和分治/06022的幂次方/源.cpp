#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string Get2sExponent(int n) {
	if (n == 0) {
		return "0";
	}
	vector<int> exp;
	for (int i = 15; i >= 0; --i) {
		if ((n & 1 << i) != 0) {
			exp.push_back(i);	// 获取n的二进制形式各位为1的位次
		}
	}
	// n = 2^(exp[0]) + 2^(exp[1]) + ... + 2^(exp[size-1])
	string res = "";
	for (int i = 0; i < exp.size(); ++i) {
		if (i != 0) {
			res += "+";
		}
		if (exp[i] == 1) {
			res += "2";	// 如果是2的1次方就直接输出
		}
		else {
			res += "2(" + Get2sExponent(exp[i]) + ")";
		}
	}
	return res;
}
int main() {
	//printf("%d\n", 1 << 15);
	// 大问题—>小问题
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%s\n", Get2sExponent(n).c_str());
	}
	return 0;
}