#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<char> myStack;
	char strArr[10010] = { 0 };
	scanf("%s", strArr);
	for (int i = 0; strArr[i] != '\0'; ++i) {
		if (strArr[i] == '<' || strArr[i] == '(' || strArr[i] == '[' || strArr[i] == '{') {
			myStack.push(strArr[i]);
		}
		else if (strArr[i] == '>') {
			if (myStack.empty()||myStack.top()!='<') {
				printf("no\n");
				return 0;
			}
			else {
				myStack.pop();
			}
		}
		else if (strArr[i] == ')') {
			if (myStack.empty() || myStack.top() != '(') {
				printf("no\n");
				return 0;
			}
			else {
				myStack.pop();
			}
		}
		else if (strArr[i] == ']') {
			if (myStack.empty() || myStack.top() != '[') {
				printf("no\n");
				return 0;
			}
			else {
				myStack.pop();
			}
		}
		else if (strArr[i] == '}') {
			if (myStack.empty() || myStack.top() != '{') {
				printf("no\n");
				return 0;
			}
			else {
				myStack.pop();
			}
		}
	}
	if (myStack.empty()) {
		printf("yes\n");
	}
	else {
		printf("no\n");
	}

	return 0;
}