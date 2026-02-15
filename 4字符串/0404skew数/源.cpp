#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	string str;
	while (cin >> str) {
		int sum = 0;
		for (int i = 0; i < str.size(); ++i) {
			sum += (str[i] - '0') * ((1 << (str.size() - i)) - 1);
		}
		printf("%d\n", sum);
	}
	return 0;
}