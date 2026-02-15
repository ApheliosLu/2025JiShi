#include<stdio.h>
using namespace std;

int Reverse(int n) {
	int reverse = 0;
	int remain;
	while (true) {
		remain = n % 10;
		n = n / 10;
		reverse = reverse * 10 + remain;
		if (0 == n) {
			break;
		}
	}
	return reverse;
}

int main() {
	//int n = 1234;
	//int reverse = 0;
	//int remain;

	////while (n > 0) {
	////	remain = n % 10;
	////	n = n / 10;
	////	reverse = reverse * 10 + remain;
	////}

	//// 另一种写法
	//while (true) {	// 纯C则while(1),死循环
	//	remain = n % 10;
	//	n = n / 10;
	//	reverse = reverse * 10 + remain;
	//	if (n == 0) {
	//		break;
	//	}
	//}

	/*int n = 1234;
	int reverse = Reverse(n);*/

	// 1000-->9999
	for (int n = 1000; n <= 9999; ++n) {
		if (Reverse(n) == n * 9) {
			printf("%d\n", n);
		}
	}
	return 0;
}