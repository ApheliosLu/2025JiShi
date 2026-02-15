#define _CRT_SECURE_NO_WARNIGNS
#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> myQueue;
	if (myQueue.empty()) {
		printf("myQueue is empty!\n");
	}
	for (int i = 0; i < 10; ++i) {
		myQueue.push(i);
		printf("front = %d, back = %d\n", myQueue.front(), myQueue.back()); 
	}
	printf("------------------------------\n");
	for (int i = 0; i < 9; ++i) {
		myQueue.pop();
		printf("front = %d, back = %d\n", myQueue.front(), myQueue.back()); 
	}
	return 0;
}