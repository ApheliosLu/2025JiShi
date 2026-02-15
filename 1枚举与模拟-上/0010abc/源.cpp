#include<iostream>
using namespace std;

int main() {
	int a, b, c;
	for (a = 0; a <= 9; a++) {
		for (b = 0; b <= 9; b++) {
			for (c = 0; c <= 9; c++){
				if (532 == (100 * a + 10 * b + c) + (100 * b + 11 * c)) {
					printf("%d %d %d\n", a, b, c);
					//cout << a << endl << b << "\n" << c;
				}
			}
		}
	}
	return 0;
}