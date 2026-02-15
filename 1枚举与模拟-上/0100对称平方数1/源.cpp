#include<stdio.h>
using namespace std;

int Reverse(int n) {
	int reverse = 0;
	int remain;
	while (n > 0) {
		remain = n % 10;
		n = n / 10;
		reverse = reverse * 10 + remain;
	}
	return reverse;
}

int main() {
	for (int n = 0; n <= 256; ++ n) {
		if (n * n == Reverse(n * n)) {
			printf("%d\n", n);
		}
	}
	return	0;
}