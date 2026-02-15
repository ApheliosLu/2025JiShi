#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
	int N;
	char strArr[200];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s", strArr);
		string str = strArr;
		int oneAcc = 0;	// 连续1的个数
		int forward = 0;	// 前移次数
		for (int j = 0; j < str.length(); ++j) {
			if (oneAcc == 5) {
				++forward;
				oneAcc = 0;
				continue;
			}
			str[j - forward] = str[j];
			if (str[j] == '1') {
				++oneAcc;
			}
			else {
				oneAcc = 0;
			}
		}
		str.erase(str.length() - forward);
		printf("%s\n", str.c_str());
	}
	return 0;
}