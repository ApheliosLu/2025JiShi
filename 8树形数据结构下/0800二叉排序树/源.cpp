#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
};
void InsertBST(TreeNode*& proot, int data) {
	TreeNode* pNew = new TreeNode;
	pNew->data = data;
	pNew->left = NULL;
	pNew->right = NULL;

	if (proot == NULL) {
		proot = pNew;
		printf("-1\n");
	}
	else {
		TreeNode* pCur = proot;	// pCur 向下探索
		TreeNode* pPre;	// pPre指向pCur的父亲
		while (1) {
			if (pCur->data > data) {
				pPre = pCur;
				pCur = pCur->left;
				if (pCur == NULL) {
					pPre->left = pNew;
					printf("%d\n", pPre->data);
					break;
				}
			}
			else {
				pPre = pCur;
				pCur = pCur->right;
				if (pCur == NULL) {
					pPre->right = pNew;
					printf("%d\n", pPre->data);
					break;
				}
			}
		}
	}
}
int main() {
	int N;
	scanf("%d", &N);
	TreeNode* proot = NULL;
	for (int i = 0; i < N; ++i) {
		int data;
		scanf("%d", &data);
		InsertBST(proot, data);
	}
	return 0;
}