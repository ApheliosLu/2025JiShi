#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student {
	int number;
	int score;
};
bool compare(Student lhs, Student rhs) {
	if (lhs.score < rhs.score) {
		return true;
	}
	else if (lhs.score == rhs.score && lhs.number < rhs.number) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	vector<Student> vec(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &vec[i].number, &vec[i].score);
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", vec[i].number, vec[i].score);
	}
	return 0;
}