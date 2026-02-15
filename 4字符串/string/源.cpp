#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {

	//// string 第一类操作 类似int，float等内置类型
	//string str1 = "Hello,";
	//string str2 = "World!";
	//string str3;
	//str3 = "Hello,";	// string 支持 = 赋值
	//str3 = str2;
	//// string 支持 == 判断内容是否相同
	//bool isSame = false;
	//isSame = (str3 == str2);
	//// string 支持 + 连接操作
	//str3 = str1 + str2;
	//// string 支持 < <= > >= 比较大小 字典序
	//bool isLarger = false;
	//isLarger = (str1 > str2);

	//// 第二类操作 string 类似 vector<char>
	//string str4 = "abcdef";
	//char ch;
	//ch = str4[0];
	//ch = str4[1];
	//str4.push_back('g');
	//str4.pop_back();

	//string::iterator it;
	//for (it = str4.begin(); it != str4.end(); ++it) {
	//	printf("*it = %c\n", *it);
	//}
	//it = str4.begin();
	//str4.insert(it, 'A');
	//it = str4.begin();
	//str4.erase(it);
	////str4.clear();

	//// string 额外功能 对vector拓展了insert和erase的用法
	//// string 使用整数下标，插入删除多个字符
	//str4.insert(0, "xyz");	// 整数下标 ， 字符串常量
	//str4.erase(0, 3);	// 两个整数下标 删除的范围 [0,3)

	//// string 获取子串
	//string str5;
	//str5 = str4.substr(0, 3);	// 从0开始 长度为3

	//// string 字符串匹配
	//string str6 = "howdoyoudo";
	//int pos = str6.find("do", 9);	// 查找子串，查找位置起点
	//if(pos == string::npos){
	//	printf("do is not found!\n");
	//}

	//// string 和其他类型转换
	//int i = 1234;
	//string str7 = to_string(i);
	//float f = 3.14;
	//str7 = to_string(f);
	//string str8 = "3.14159";
	//f = stof(str8);
	//str8 = "314159";
	//i = stoi(str8);

	//// string  输入输出
	//char arr[100];
	//scanf("%s", arr);
	//string str9;
	//str9 = arr;	// 先读字符数组，再转成string
	//printf("str9 = %s\n", str9.c_str());	// 输出使用.c_str()

	string str10;
	cin >> str10;
	cout << "str10 = " << str10 << "\n";
	return 0;
}