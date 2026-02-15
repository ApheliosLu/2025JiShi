#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main() {
	char str[200] = { 0 };
	scanf("%s", str);

	map<char, vector<int>> timesMap;	// 记录每个字符的(多个）位置和次数
	vector<char> charSeq;	// 每个字符出现的先后顺序

	for (int i = 0; str[i] != '\0'; ++i) {
		timesMap[str[i]].push_back(i);	// 每个字符的位置
		// 如果是第一次出现
		if (timesMap[str[i]].size() == 1) {
			charSeq.push_back(str[i]);
		}
	}
	vector<char>::iterator seqIt;

	for (seqIt = charSeq.begin(); seqIt != charSeq.end(); ++seqIt) {
		if (timesMap[*seqIt].size() > 1) {
			vector<int>::iterator posIt = timesMap[*seqIt].begin();
			printf("%c:%d", *seqIt, *posIt);
			for (posIt = timesMap[*seqIt].begin() + 1;
				posIt != timesMap[*seqIt].end();
				++posIt) {
				printf(",%c:%d", *seqIt, *posIt);
			}
			printf("\n");
		}
	}

	return 0;
}