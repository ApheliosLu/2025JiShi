#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>	
using namespace std;

int FactorSum(int i) {	// 求某个数的因子之和
	int res = 0;
	for (int j = 1; j < i; ++j) {
		if (i % j == 0) {
			res += j;
		}
	}
	return res;
}
int main() {
	vector<int> Evec;
	vector<int> Gvec;
	for (int i = 2; i <= 60; ++i) {
		if (i == FactorSum(i)) {
			Evec.push_back(i);
		}
		else if (i < FactorSum(i)) {
			Gvec.push_back(i);
		}
	}

	vector<int>::iterator it;
	printf("E:");
	for (it = Evec.begin(); it != Evec.end(); ++it) {
		printf(" %d", *it);
	}
	printf("\n");
	printf("G:");
	for (it = Gvec.begin(); it != Gvec.end(); ++it) {
		printf(" %d", *it);
	}
	printf("\n");
	return 0;
}