#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
using namespace std;

double GetGP(int score) {
	if (score >= 90) {
		return 4.0;
	}
	else if (score >= 85) {
		return 3.7;
	}
	else if (score >= 82) {
		return 3.3;
	}
	else if (score >= 78) {
		return 3.0;
	}
	else if (score >= 75) {
		return 2.7;
	}
	else if (score >= 72) {
		return 2.3;
	}
	else if (score >= 68) {
		return 2.0;
	}
	else if (score >= 64) {
		return 1.5;
	}
	else if (score >= 60) {
		return 1.0;
	}
	else {
		return 0;
	}
}

int main() {
	int number;
	scanf_s("%d", &number);
	int point[11];	// 学分数组
	int score[11];	// 成绩数组
	double totalpoint = 0;	// 总学分
	for (int i = 0; i < number; i++) {
		scanf_s("%d", &point[i]);
		totalpoint += point[i];
	}
	double totalGP = 0;	// 所有学科绩点之和
	for (int i = 0; i < number; i++) {
		scanf_s("%d", &score[i]);
		totalGP += GetGP(score[i]) * point[i];
	}
	printf("%.2lf", totalGP / totalpoint);
	return 0;
}