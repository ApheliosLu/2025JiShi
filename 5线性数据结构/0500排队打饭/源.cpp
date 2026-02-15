#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct Student {
	int a;
	int t;
	int b;
};
int main() {
	int n;
	scanf("%d", &n);
	queue<Student> myQueue;
	for (int i = 0; i < n; ++i) {
		Student s;
		scanf("%d%d%d", &s.a, &s.t, &s.b);
		myQueue.push(s);
	}
	long long curtime = 0;
	while (myQueue.empty() == false) {
		Student top = myQueue.front();
		myQueue.pop();
		if (top.a + top.b < curtime) {
			printf("-1 ");
			continue;
		}
		curtime = max(curtime,(long long) top.a);
		printf("%lld ", curtime);
		curtime += top.t;
	}
	printf("\n");
	return 0;
}