#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	// 987 = 900 + 80 +7
	int T;
	map<int, string> unit = {
		{ 1,"I" }, { 2,"II" }, { 3,"III" }, { 4,"IV" }, { 5,"V" },
		{ 6,"VI" }, { 7,"VII" }, { 8,"VIII" }, { 9,"IX" }
	};
	map<int, string> ten = {
		{10,"X"},{20,"XX"},{30,"XXX"},{40,"XL"},{50,"L"},
		{60,"LX"},{70,"LXX"},{80,"LXXX"},{90,"XC"}
	};
	map<int, string> hundred = {
		{100,"C"},{200,"CC"},{300,"CCC"},{400,"CD"},{500,"D"},
		{600,"DC"},{700,"DCC"},{800,"DCCC"},{900,"CM"}
	};
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		int n;
		scanf("%d", &n);
		string res;
		if (n == 1000) {
			res = 'M';
		}
		else if (n >= 100) {
			int u = n % 10;	// 个位
			int t = (n / 10) % 10 * 10;	// 十位
			int h = (n / 100) % 10 * 100;	// 百位
			res = hundred[h] + ten[t] + unit[u];
		}
		else if (n >= 10) {
			int u = n % 10;	
			int t = (n / 10) % 10 * 10;	
			res = ten[t] + unit[u];
		}
		else {
			res = unit[n % 10];
		}
		printf("%s\n", res.c_str());
	}
	return	0;
}