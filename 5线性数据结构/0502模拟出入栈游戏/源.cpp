#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

int main() {
	char arr[30];
	while (scanf("%s", arr) != EOF) {
		stack<char> myStack;
		char curTop;
		char toPush = 'a';
		bool isOk = true;
		for (int i = 0; i < 26; ++i) {
			if (myStack.empty()) {	// 如果栈为空先压入一个元素
				myStack.push(toPush);
				++toPush;
			}
			// 考察输入的元素和当前栈顶的大小关系
			curTop = myStack.top();
			if (arr[i] > curTop) {	// 如果当前栈顶小，继续压入 
				for (char ch = toPush; ch <= arr[i]; ++ch) {	// 一直压进去
					myStack.push(ch);
				}
				myStack.pop();	// 最后弹出 arr[i]（因为 arr[i] 是目标字符）
				toPush = arr[i] + 1;	// 更新 toPush = arr[i] + 1（准备压入下一个可能的字符）
			}
			else if (arr[i] == curTop) {	// 直接弹出栈顶元素（因为匹配成功）
				myStack.pop();
			}
			else {	// 栈顶元素大
				isOk = false;
				break;
			}
		}
		if (isOk) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
	return 0;
}