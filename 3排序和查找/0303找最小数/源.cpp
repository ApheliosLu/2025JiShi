#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Node {
	int x;
	int y;
};
int main() {
	int n;
	scanf("%d", &n);
	Node arr[1000];
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &arr[i].x, &arr[i].y);
	}
	int x, y;
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			x = arr[i].x;
			y = arr[i].y;
		}
		if (arr[i].x < x) {
			x = arr[i].x;
			y = arr[i].y;
		}
		else if(arr[i].x==x&&arr[i].y<y){
			y = arr[i].y;
		}
	}
	printf("%d %d\n", x, y);
	return 0;
}