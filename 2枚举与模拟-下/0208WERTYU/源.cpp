#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	char strArr[200] = { 0 };
	map<char, char> toCorrect = {
		{' ',' '},
		{'2','1'},{'3','2'},{'4','3'},{'5','4'},{'6','5'},{'7','6'},{'8','7'},{'9','8'},{'0','9'},{'-','0'},{'=','-'},
		{'W','Q'},{'E','W'},{'R','E'},{'T','R'},{'Y','T'},{'U','Y'},{'I','U'},{'O','I'},{'P','O'},{'[','P'},{']','['},
		{'S','A'},{'D','S'},{'F','D'},{'G','F'},{'H','G'},{'J','H'},{'K','J'},{'L','K'},{';','L'},{'\'',';'},
		{'X','Z'},{'C','X'},{'V','C'},{'B','V'},{'N','B'},{'M','N'},{',','M'},{'.',','},{'/','.'}
	};
	while (fgets(strArr, 200, stdin) != NULL) {
		// 使用fgets配合循环处理未知数量行的输入	fgets 函数在读取一行输入时会包含行尾的换行符 (\n)
		for (int i = 0; strArr[i] != '\0'; ++i) {
			if (strArr[i] == '\n') {	// 去除多余的换行
				strArr[i] = '\0';
			}
			strArr[i] = toCorrect[strArr[i]];
		}
		printf("%s\n", strArr);
	}
	return 0;
}