#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

char IntToChar(int x) {	// 数字变成字符
	if (x < 10) {
		return x + '0';	// 数字0变成字符0 加上48  x = 3 → 3 + '0' = 3 + 48 = 51（ASCII 码中的 '3'）
	}
	else {
		return x - 10 + 'a';	// x = 11 → 11 - 10 + 'a' = 1 + 97 = 98（ASCII 码中的 'b'）
		// 字符 'a' 在 ASCII 码中的值是 97。计算时，先减去 10（因为 'a' 对应 10），再加上 'a' 的 ASCII 值。
	}
}

int CharToInt(char c) {	// 字符变成数字
	if (c >= '0' && c <= '9') {
		return c - '0';	// 本身是字符0到9 直接减去48
	}
	else {
		return c - 'A' + 10;
	}
}

int main() {
	int M, N;
	char strArr[100];
	scanf("%d%d", &M, &N);
	scanf("%s", strArr);
	string str = strArr;
	long long number = 0;
	for (int i = 0; i < str.size(); ++i) {	// 从m进制变成十进制
		number *= M;
		number += CharToInt(str[i]);
	}
	vector<char> answer;
	if (number == 0) {
		answer.push_back('0');
	}
	else {
		while (number != 0) {	// 从十进制变成n进制
			answer.push_back(IntToChar(number % N));
			number /= N;
		}
	}
	for (int i = answer.size() - 1; i >= 0; --i) {	// 逆序输出
		printf("%c", answer[i]);
	}
	printf("\n");
	return 0;
}