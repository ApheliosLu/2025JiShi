#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Mouse {
	int weight;
	char color[20];
};

bool Compare(Mouse lhs, Mouse rhs) {
	return lhs.weight > rhs.weight;
}
int main() {
	int N;
	vector<Mouse> vec;
	while (scanf("%d", &N) != EOF) {	// ∂‡∞∏¿˝ ‰»Î
		for (int i = 0; i < N; ++i) {
			Mouse mouse;
			scanf("%d%s", &mouse.weight,mouse.color);
			vec.push_back(mouse);
		}
		sort(vec.begin(), vec.end(), Compare);
		for (auto &c:vec) {
			printf("%s\n", c.color);
		}
	}
	return 0;
}