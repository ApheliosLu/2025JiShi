#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//void func2() {
//	return;
//}
//void func1() {
//	func2();
//	return;
//}
//int main() {
//	func1();
//	func2();
//	return 0;
//}

void func(int i) {
	if (i > 0) {
		func(i - 1);
	}
	else {
		return;
	}
}
int main() {
	func(10);
	return 0;
}