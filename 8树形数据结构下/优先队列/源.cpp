#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;


int main() {
	int arr[6] = { 2,4,6,1,3,5 };
	priority_queue<int> myPQueue;
	for (int i = 0; i < 6; ++i) {
		myPQueue.push(arr[i]);
		printf("top = %d\n", myPQueue.top());
	}
	cout << string(50, '-') << endl;
	while (myPQueue.empty() == false) {
		printf("pop, top = %d\n", myPQueue.top());
		myPQueue.pop();
	}
	return 0;
}