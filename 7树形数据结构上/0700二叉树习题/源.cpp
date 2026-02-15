#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int x, y;
	vector<int> fx;
	vector<int> fy;
	scanf("%d%d", &x, &y);
	while (x > 0) {
		fx.push_back(x);
		x /= 2;
	}
	while (y > 0) {
		fy.push_back(y);
		y /= 2;
	}
	for (int i = fx.size() - 1, j = fy.size() - 1;; --i, --j) {
		if (i < 0 || j < 0 || fx[i] != fy[j]) {
			printf("%d\n", fx[i + 1]);
			break;
		}
	}

	return 0;
}