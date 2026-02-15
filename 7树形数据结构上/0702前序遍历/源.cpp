#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> PreOrder;
vector<int> InOrder;
vector<int> PostOrder;
unordered_map<int, int> valueToPos;	// 空间换时间
void Rebuild(int postLeft, int postRight, int inLeft, int inRight, int preLeft, int preRight) {
	if (postLeft > postRight) {
		return;
	}
	int root = PostOrder[postRight];	// // 找到根了
	int leftsize = valueToPos[root] - inLeft;	// 左子树的长度
	PreOrder[preLeft] = root;
	Rebuild(postLeft, postLeft + leftsize - 1, inLeft, inLeft + leftsize - 1, preLeft+1, preLeft + leftsize );
	Rebuild(postLeft + leftsize, postRight - 1, inLeft + leftsize + 1, inRight, preLeft + leftsize + 1, preRight);
}
int main() {
	int N;
	scanf("%d", &N);
	PreOrder.resize(N);
	InOrder.resize(N);
	PostOrder.resize(N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &PostOrder[i]);
	}
	for (int i = 0; i < N; ++i) {
		scanf("%d", &InOrder[i]);
		valueToPos[InOrder[i]] = i;	// 
	}
	Rebuild(0, N - 1, 0, N - 1, 0, N - 1);
	printf("%d\n", PreOrder.back());
	return 0;
}