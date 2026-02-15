#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<cstring>
using namespace std;

void NextDay(int& year, int& month, int& day) {
	// & 出现在定义or形参当中表示引用；出现在其他位置表示取地址

	// 存储月份和天数对应关系
	int dayofMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	bool isLeap;	// 是否是闰年
	isLeap = year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
	if (isLeap) {
		dayofMonth[2] = 29;
	}
	else {
		dayofMonth[2] = 28;
	}

	++day;
	if (day > dayofMonth[month]) {
		day = 1;
		++month;
	}
	if (month > 12) {
		month = 1;
		++year;
	}

	//printf("NextDay year = %d, month = %d, day = %d\n", year, month, day);
}

int main() {
	int y, n;
	while (scanf("%d%d", &y, &n) != EOF) {
		int next = 1;
		int curmonth = 1;
		int curday = 1;
		while (1) {
			if (next == n) {
				break;
			}
			NextDay(y, curmonth, curday);
			++next;
		}
		printf("%04d-%02d-%02d\n", y, curmonth, curday);	// %04d表示占4位，不足则用0填充
	}
	return 0;
}