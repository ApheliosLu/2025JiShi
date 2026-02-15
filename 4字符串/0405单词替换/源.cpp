#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	char sentence[110];
	fgets(sentence, 110, stdin);	// 读取一行到sentence
	string word;	// 读取一个个字母
	vector<string> words;	// 读取一整个单词 保存
	multimap<string, int> wordToIdx;	// 
	// 循环从sentence中读取单词
	for (int i = 0; sentence[i] != '\0'; ++i) {
		if (sentence[i] == ' ' || sentence[i] == '\n') {	// 每当读到空格就把前面的单词保存到words中
			words.push_back(word);
			wordToIdx.insert({ word,words.size() - 1 });
			word.clear();
		}
		else {
			word.push_back(sentence[i]);
		}
	}
	char from[30], to[30];
	scanf("%s%s", from, to);
	multimap<string, int>::iterator it;
	for (it = wordToIdx.lower_bound(from); it != wordToIdx.upper_bound(from); ++it) {
		words[it->second] = to;	// [lower_bound(from), upper_bound(from)) 包含了 所有键等于 from 的元素
	}
	for (int i = 0; i < words.size(); ++i) {
		if (i != 0) {
			printf(" ");
		}
		printf("%s", words[i].c_str());
	}
	printf("\n");
	return 0;
}