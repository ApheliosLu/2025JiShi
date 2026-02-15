#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
// abc
// a -- bc
//      b -- c
//        -- c
//      c -- b
// b -- ac
// b -- a -- c
// b -- c -- a
// c -- ab
// c -- a -- b
// c -- b -- a
// 现在有n个字母，循环取出其中1个i，递归处理剩余n-1个，在n-1的结果的基础上连接上i
// 如果只有1个，就直接加入
// 选择-排除-递归：每次选择一个字符，排除已选字符，对剩余字符递归处理
// 回溯：通过栈结构记录当前路径，完成一个分支后回退尝试其他可能
void permulation(vector<char>& stack, char ch, int pos, string letters, int length) {
	stack.push_back(ch);
	if (pos + 1 == length) {	// 已是最后一个字符
		for (int i = 0; i < stack.size(); ++i) {
			printf("%c", stack[i]);	// 直接将栈内字符输出
		}
		printf("\n");
	}
	else {
		for (int i = 0; i < letters.size(); ++i) {
			string newLetters = letters;
			char ch = newLetters[i];
			newLetters.erase(i,1);	// 从位置i开始，删除1个字符
			permulation(stack, ch, pos + 1, newLetters, length);
		}
	}
	stack.pop_back();	// 移除当前字符，尝试其他可能
	return;
}
int main() {
	vector<char> stack;	// 用一个栈记录已经访问过的字母
	char letters[10];
	scanf("%s", letters);
	int length = strlen(letters);
	for (int i = 0; i < length; ++i) {
		string newLetters = letters;
		char ch = newLetters[i];
		newLetters.erase(i,1);
		permulation(stack, ch, 0, newLetters, length);
	}

	return 0;
}