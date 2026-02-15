#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

int main() {
	char strArr[300] = { 0 };
	map<char, int> priority = {
		{'\n',0},
		{'+',1},{'-',1},
		{'*',2},{'/',2}
	};
	while (fgets(strArr, 300, stdin) != NULL) {
		string str = strArr;
		if (str == "0\n") {
			break;
		}
		string numStr = "";
		stack<char> opStack;
		stack<double> numStack;
		for (int i = 0;; ++i) {
			if (str[i] >= '0' && str[i] <= '9') {
				numStr.push_back(str[i]);
			}
			else if (str[i] == ' ') {
				if (numStr.size() > 0) {	// 操作数读取完成
					double num = stod(numStr);
					numStack.push(num);
					numStr = "";
				}
			}
			else {	// 运算符
				if (str[i] == '\n' && numStr.size() > 0) {// 操作数读取完成
					double num = stod(numStr);
					numStack.push(num);
					numStr = "";
				}
				while(!opStack.empty()&&priority[str[i]]<=priority[opStack.top()]){
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
						numStack.push(lhs - rhs);
					}
					else if (curOp == '*') {
						numStack.push(lhs * rhs);
					}
					else if (curOp == '/') {
						numStack.push(lhs / rhs);
					}
				}

				// 栈为空 或者 新op的优先级高于栈顶
				if (str[i] == '\n') {
					printf("%.2lf\n", numStack.top());
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