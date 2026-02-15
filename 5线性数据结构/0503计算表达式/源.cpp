#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

int main() {
	// 运算符栈 操作数栈
	char str[1000] = { 0 };
	map<char, int> priority = {
		{'\0',0},{'+',1},{'-',1},{'*',2},{'/',2}
	};
	while (scanf("%s", str) != EOF) {
		string numStr = "";
		stack<char> opStack;
		stack<double> numStack;
		for (int i = 0;; ++i) {
			if (str[i] >= '0' && str[i] <= '9') {
				numStr.push_back(str[i]);
			}
			else {
				double num = stod(numStr);	// 将字符转换为double
				numStr = "";
				numStack.push(num);


				// 什么时候弹栈？ 栈非空&&新op的优先级不高于栈顶的优先级
				// 循环弹栈和计算
				while (!opStack.empty()
					&& priority[str[i]] <= priority[opStack.top()]) {
					double rhs = numStack.top();
					numStack.pop();
					double lhs = numStack.top();
					numStack.pop();
					char curOp = opStack.top();
					opStack.pop();

					if (curOp == '+') {
						numStack.push(lhs + rhs);
					}
					else if (curOp == '-') {
						numStack.push(lhs -rhs);
					}
					else if (curOp == '*') {
						numStack.push(lhs * rhs);
					}
					else if (curOp == '/') {
						numStack.push(lhs / rhs);
					}
				}

				// 栈空 或 新op的优先级高于栈顶
				if (str[i] == '\0') {
					printf("%d\n", (int)numStack.top());
					break;
				}
				else {
					opStack.push(str[i]);
				}
			}
		}
	}

	return 0;
}