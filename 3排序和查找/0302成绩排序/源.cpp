#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student {
	char name[20];
	int score;
	int seq;	// 学生序号保证稳定排序
};

bool Compare0(Student lhs, Student rhs) {	// 0 从高到低
	if (lhs.score > rhs.score) {
		return true;
	}
	else if (lhs.score == rhs.score && lhs.seq < rhs.seq) {
		return true;
	}
	else {
		return false;
	}
}

bool Compare1(Student lhs, Student rhs) {	// 1 从低到高
	if (lhs.score < rhs.score) {
		return true;
	}
	else if (lhs.score == rhs.score && lhs.seq < rhs.seq) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int N;
	scanf("%d", &N);
	vector<Student> vec(N);
	int flag;
	scanf("%d", &flag);
	for (int i = 0; i < N; ++i) {
		scanf("%s%d", vec[i].name, &vec[i].score);
		vec[i].seq = i;
	}
	if (flag == 0) {
		sort(vec.begin(), vec.end(), Compare0);
	}
	else{
		sort(vec.begin(), vec.end(), Compare1);
	}
	for (int i = 0; i < N; ++i) {
		printf("%s %d\n", vec[i].name, vec[i].score);
	}
	return 0;
}