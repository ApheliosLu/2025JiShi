#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>	// O(1)
using namespace std;

int main() {
	int N;
	char strArr[20] = { 0 };
	scanf("%d", &N);
	scanf("%s", strArr);
	if (N < 4) {
		printf("-1\n");
		return 0;
	}
	string str = strArr;

	queue<string> toVisit;	// 待访问的字符串
	toVisit.push(str);
	unordered_map<string, int> distanceMap;
	distanceMap.insert({ str,0 });
	while (toVisit.empty() == false) {
		string current = toVisit.front();
		if (current.find("2012") != string::npos) {	// 找到了
			printf("%d\n", distanceMap[current]);
			break;
		}
		toVisit.pop();
		for (int i = 0; i < current.size() - 1; ++i) {
			string next = current;
			char temp = next[i];	// 交换字符
			next[i] = next[i + 1];
			next[i + 1] = temp;
			if (distanceMap.count(next) == 0) {	// 不在map中
				toVisit.push(next);
				distanceMap.insert({ next,distanceMap[current] + 1 });
			}
		}
	}
	if (toVisit.empty() == true) {	// 没找到
		printf("-1\n");
	}
	return 0;
}