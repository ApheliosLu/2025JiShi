#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
	unsigned int u;
	while (scanf("%u",&u)!=EOF) {
		vector<int> binVec;
		if (u == 0) {
			printf("0\n");
			continue;
		}
		while (u>0) {
			binVec.push_back(u % 2);
			u /= 2;
		}
		for (int i = binVec.size() - 1; i >= 0; i--) {
			printf("%d", binVec[i]);
		}
		printf("\n");
	}
	return 0;
}