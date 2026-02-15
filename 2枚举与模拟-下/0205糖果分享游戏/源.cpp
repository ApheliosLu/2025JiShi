#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>	
using namespace std;

// 分享糖果
void ShareCandy(vector<int>& student) {
	int size = student.size();
	vector<int> share(size);	// 保存交换前的糖果的一半
	for (int i = 0; i < size; ++i) {
		share[i] = student[i] / 2;
	}
	for (int i = 0; i < size; ++i) {
		student[i] -= share[i];
		student[(i + 1) % size] += share[i];
	}
	for (int i = 0; i < size; ++i) {
		if (student[i] % 2 != 0) {
			++student[i];
		}
	}
}

// 检查相等
bool CheckCandy(vector<int>& student) {
	int size = student.size();
	int first = student[0];
	for (int i = 1; i < size; ++i) {
		if (first != student[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int N;
	while (scanf("%d", &N) != EOF) {
		if (N == 0) {
			break;
		}

		vector<int> student(N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &student[i]);
		}

		int turn = 0;
		while (CheckCandy(student) == false) {
			ShareCandy(student);
			++turn;
		}
		printf("%d %d\n", turn, student[0]);
	}
	return	0;
}