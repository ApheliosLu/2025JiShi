#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
using namespace std;

string GetInteger(string a) {
	return a.substr(0, a.find('.'));
}
string GetFraction(string a) {
	return a.substr(a.find('.') + 1, a.size() - a.find('.'));
}
// 使用引用参数 返回信息
void FractionPlus(string& res, int& carry, string fa, string fb) {
	int size = max(fa.size(), fb.size());
	while (fa.size() < size) {
		fa.push_back('0');
	}
	while (fb.size() < size) {
		fb.push_back('0');
	}

	res.resize(size);	// 给res申请内存空间
	carry = 0;
	for (int i = size - 1; i >= 0; --i) {
		// '0' = '0'
		// '3' = '0' +3
		if (fa[i] + fb[i] +carry- '0' > '9') {
			res[i] = fa[i] + fb[i]+carry - '0' - 10;
			carry = 1;
		}
		else {
			res[i] = fa[i] + fb[i]+carry - '0';
			carry = 0;
		}
	}
	return;
}
void IntergerPlus(string& res, int carry, string ia, string ib) {
	res.clear();
	for (int i = ia.size() - 1, j = ib.size() - 1;
		i >= 0 || j >= 0 || carry == 1;
		--i, --j) {
		if (i >= 0 && j >= 0) {
			if (ia[i] + ib[j] + carry - '0' > '9') {
				res.insert(res.begin(), ia[i] + ib[j] + carry - '0' - 10);
				carry = 1;
			}
			else {
				res.insert(res.begin(), ia[i] + ib[j] + carry - '0' );
				carry = 0;
			}
		}
		else if (i >= 0 && j < 0) {
			if (ia[i]  + carry  > '9') {
				res.insert(res.begin(), ia[i]  + carry - 10);
				carry = 1;
			}
			else {
				res.insert(res.begin(), ia[i]  + carry );
				carry = 0;
			}
		}
		else if (j >= 0 && i < 0) {
			if (ib[j] + carry  > '9') {
				res.insert(res.begin(), ib[j] + carry - 10);
				carry = 1;
			}
			else {
				res.insert(res.begin(), ib[j] + carry);
				carry = 0;
			}
		}
		else {
			res.insert(res.begin(), '1');
			carry = 0;
		}
	}

	return;
}
int main() {
	// 高精度运算 字符串模拟竖式运算
	//string a = "12345.6789";	// "11"
	//string b = "333.33333";		// "99"
	char arra[1000] = { 0 };
	char arrb[1000] = { 0 };
	while (scanf("%s%s", arra, arrb) != EOF) {
		string a = arra;
		string b = arrb;
		string ia = GetInteger(a);
		string ib = GetInteger(b);
		string fa = GetFraction(a);
		string fb = GetFraction(b);

		string fres;
		int carry;
		FractionPlus(fres, carry, fa, fb);
		string ires;
		IntergerPlus(ires, carry, ia, ib);

		printf("%s.%s\n", ires.c_str(), fres.c_str());
	}
	
	return 0;
}
