#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) {
			break;
		}
		stack<int> myStack;
		for (int i = 0; i < n; ++i) {
			char op[2];
			scanf("%s", op);
			if (op[0] == 'A') {
				if (myStack.empty()) {
					printf("E\n");
				}
				else {
					printf("%d\n", myStack.top());
				}
			}
			else if (op[0] == 'O') {
				if (myStack.empty()) {
					continue;
				}
				else {
					myStack.pop();
				}
			}
			else if (op[0] == 'P') {
				int data;
				scanf("%d", &data);
				myStack.push(data);
			}
		}
	}

	return 0;
}