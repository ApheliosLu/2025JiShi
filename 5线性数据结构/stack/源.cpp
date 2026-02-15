#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<int> myStack;
	if (myStack.empty()) {
		printf("myStack is empty!\n");
	}
	for (int i = 0; i < 10; ++i) {
		myStack.push(i);
		printf("myStack top is %d\n", myStack.top());
	}
	cout << string(50, '*') << endl;
	for (int i = 0; i < 9; ++i) {
		myStack.pop();
		printf("myStack top is %d\n", myStack.top());
	}

	return 0;
}