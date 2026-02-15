#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
};
void InserBST(TreeNode*& root, int data) {
	TreeNode* pNew = new TreeNode;
	pNew->data = data;
	pNew->left = NULL;
	pNew->right = NULL;
	if (root == NULL) {
		root = pNew;
	}
	else {
		TreeNode* pPre = root;
		TreeNode* pCur;
		while (true) {
			if (data == pPre->data) {
				break;
			}
			else if (data < pPre->data) {
				pCur = pPre->left;
				if (pCur == NULL) {
					pPre->left = pNew;
					break;
				}
				else {
					pPre = pCur;
				}
			}
			else {
				pCur = pPre->right;
				if (pCur == NULL) {
					pPre->right = pNew;
					break;
				}
				else {
					pPre = pCur;
				}
			}
		}
	}
}
void PreOrder(TreeNode* proot) {
	if (proot == NULL) {
		return;
	}
	else {
		printf("%d ", proot->data);
		PreOrder(proot->left);
		PreOrder(proot->right);
	}
}
void InOrder(TreeNode* proot) {
	if (proot == NULL) {
		return;
	}
	else {
		InOrder(proot->left);
		printf("%d ", proot->data);
		InOrder(proot->right);
	}
}
void PostOrder(TreeNode* proot) {
	if (proot == NULL) {
		return;
	}
	else {
		PostOrder(proot->left);
		PostOrder(proot->right);
		printf("%d ", proot->data);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	TreeNode* root = NULL;
	for (int i = 0; i < n; ++i) {
		int num;
		scanf("%d", &num);
		InserBST(root, num);
	}
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	return 0;
}