#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

void NextDay(int& year, int& month, int& day) {	// 已知当前求下一天
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

void Swap(int& lhs, int& rhs) {
	int tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

int main() {
	int date1, date2;
	while (scanf("%d%d", &date1, &date2) != EOF) {
		int year1 = date1 / 10000;
		int year2 = date2 / 10000;
		int mon1 = date1 / 100 % 100;
		int mon2 = date2 / 100 % 100;
		int day1 = date1 % 100;
		int day2 = date2 % 100;

		if (year2 < year1 ||
			year2 == year1 && mon2 < mon1 ||
			year2 == year1 && mon2 == mon1 && day2 < day1) {
			Swap(year2, year1);
			Swap(mon2, mon1);
			Swap(day2, day1);
		}
		int days = 1;
		while (1) {
			if (year1 == year2 && mon1 == mon2 && day1 == day2) {
				break;
			}
			NextDay(year1, mon1, day1);
			++days;
		}
		printf("%d\n", days);
	}
	return 0;
}