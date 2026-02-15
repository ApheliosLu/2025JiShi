#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
using namespace std;

int arr[25];
bool visit[25];
void DFS(int index, int sum, int n, int& answer) {
	if(sum == 40) {
		answer++;
		return;
	}
	for (int i = index; i < n; ++i) {
		if (visit[i] || sum + arr[i] > 40) {
			continue;
		}
		visit[i] = true;
		DFS(i + 1, sum + arr[i], n, answer);
		visit[i] = false;
	}
	return;
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		memset(visit, false, sizeof(visit));
		int answer = 0;
		DFS(0, 0, n, answer);
		printf("%d\n", answer);
	}
	return 0;
}