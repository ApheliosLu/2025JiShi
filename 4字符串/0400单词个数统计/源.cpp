#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;
int main() {
	// This is An Pencil Case
	char arr[2000] = { 0 };
	// fgets(arr, 2000, stdin); // 等价于下一行
	cin.getline(arr, sizeof(arr));   // sizeof(arr) 为 2000
	int i = 0;
	int alphaCount = 0;
	bool isSpace = true;
	int wordCount = 0;
	map<char, int> alphaMap;
	while (true) {
		if (arr[i] == '\0' || arr[i] == '\n') {
			break;
		}
		else if (arr[i] == ' ') {
			isSpace = true;
		}
		else {
			++alphaCount;
			if (isSpace) {
				++wordCount;
			}
			if (arr[i] >= 'A' && arr[i] <= 'Z') {
				// ASCII
				arr[i] += 32;
			}
			++alphaMap[arr[i]];
			isSpace = false;
		}
		++i;
	}

	printf("%d\n", alphaCount);
	printf("%d\n", wordCount);
	map<char, int>::iterator it;
	int maxTimes = 0;
	for (it = alphaMap.begin(); it != alphaMap.end(); ++it) {
		if (it->second > maxTimes) {
			maxTimes = it->second;
		}
	}

	for (it = alphaMap.begin(); it != alphaMap.end(); ++it) {
		if (it->second == maxTimes) {
			printf("%c ", it->first);
		}
	}
	printf("\n");
	printf("%d\n", maxTimes);

	return 0;
}
