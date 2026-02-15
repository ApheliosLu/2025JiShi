#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;

int main() {
	int N, M;
	int books[210];
	while (scanf("%d%d", &N, &M) != EOF) {
		map<int, int> myMap;	// <书的序号，喜欢人数>
		for (int i = 0; i < N; ++i) {
			scanf("%d", &books[i]);	// books_i表示i号人喜欢的书的序号
			myMap[books[i]]++;	
		}
		for (int i = 0; i < N; ++i) {
			if (myMap[books[i]]==1) {
				printf("BeiJu\n");
			}
			else{
				printf("%d\n", myMap[books[i]] - 1);
			}
		}
	}
	return 0;
}