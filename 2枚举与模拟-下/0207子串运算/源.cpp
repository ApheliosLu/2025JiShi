#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>	
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	char strArr[100];
	while (scanf("%s", strArr) != EOF) {
		string str = strArr;
		map<string, int> subCount;
		for (int i = 0; i < str.size(); ++i) {
			for (int j = 1; j <= str.size() - i; ++j) {
				// i是子串起始下标，j是子串长度
				string sub = str.substr(i, j);
				++subCount[sub];
			}
		}
		subCount.erase(str);
		map<string, int>::iterator it;
		for (it = subCount.begin(); it != subCount.end(); ++it) {
			if (it->second > 1) {
				printf("%s %d\n", it->first.c_str(), it->second);
			}
		}
	}
	return 0;
}