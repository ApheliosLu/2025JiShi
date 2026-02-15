#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	char strArr[1100];
	int m;
	scanf("%s", strArr);
	string str = strArr;
	scanf("%d", &m);
	string temp;
	for (int i = 0; i < m; ++i) {
		char opArr[10];
		scanf("%s", opArr);
		string op = opArr;
		if (op == "CUT") {
			int l, r;
			scanf("%d%d", &l, &r);
			temp = str.substr(l, r - l + 1);
			str.erase(l, r - l + 1);
		}
		else if (op == "COPY") {
			int l, r;
			scanf("%d%d", &l, &r);
			temp = str.substr(l, r - l + 1);
		}
		else if (op == "PASTE") {
			int p;
			scanf("%d",&p);
			str.insert(p + 1, temp);
		}
		printf("%s\n", str.c_str());
	}
	return 0;
}