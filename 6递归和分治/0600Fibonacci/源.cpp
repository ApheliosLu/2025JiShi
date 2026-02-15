#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int f(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	else {
		return f(n - 1) + f(n - 2);
	}
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", f(n));
	}
}