#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main() {
	int m;
	scanf("%d", &m);
	stack<string> myStack;
	for (int i = 0; i < m; ++i) {
		char strArr[200] = { 0 };
		scanf("%s", strArr);
		string str = strArr;
		myStack.push(str);

		stack<string> outputStack = myStack;	// outputStack”√”⁄µØ’ª
		for (int j = 1; j <= 4; ++j) {
			if (outputStack.empty()) {
				break;
			}
			printf("%d=%s ", j, outputStack.top().c_str());
			outputStack.pop();
		}
		printf("\n");
	}
	return 0;
}