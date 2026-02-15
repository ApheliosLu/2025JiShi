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
	int number[26];
	while (cin >> str) {
		memset(number, 0, sizeof(number));
		for (int i = 0; i < str.size(); ++i) {
			if ('A' <= str[i] && str[i] <= 'Z') {
				number[str[i] - 'A']++;
			}
		}
		for (int i = 0; i < 26; ++i) {
			printf("%c:%d\n", 'A' + i, number[i]);
		}
	}
	return 0;
}