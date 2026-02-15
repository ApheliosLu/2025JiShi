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
	while (fgets(sentence, 110, stdin) != NULL) {
		//vector<int> idxVec;
		bool isWordBegin = true;
		for (int i = 0; sentence[i] != '\0'; ++i) {
			if (sentence[i] == ' ' || sentence[i] == '\t' || sentence[i] == '\n' || sentence[i] == '\r') {
				isWordBegin = true;
			}
			else {
				if (isWordBegin && sentence[i] >= 'a' && sentence[i] <= 'z') {
					sentence[i] -= 32;
				}
				isWordBegin = false;
			}
		}
		printf("%s", sentence);
	}
	return 0;
}