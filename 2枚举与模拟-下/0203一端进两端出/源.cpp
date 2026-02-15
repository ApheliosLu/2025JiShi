#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>	
using namespace std;

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	vector<int> insertVec(N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &insertVec[i]);
	}
	for (int i = 0; i < K; ++i) {
		vector<int> ouputVec(N);
		for (int j = 0; j < N; ++j) {
			scanf("%d", &ouputVec[j]);
		}

		bool flag = true;
		list<int> myQueue;
		
		int j = 0, k = 0;
		for (int j = 0; j < N; ++j) {
			myQueue.push_back(insertVec[j]);
			while (!myQueue.empty() && (myQueue.front() == ouputVec[k] || myQueue.back() == ouputVec[k])) {
				if (myQueue.front() == ouputVec[k]) {
					myQueue.pop_front();
				}
				else {
					myQueue.pop_back();
				}
				++k;
			}
		}
		if (myQueue.empty()) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
	return 0;
}