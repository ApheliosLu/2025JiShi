#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
	char data;
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
		//printf("-1\n");
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
					//printf("%d\n", pPre->data);
					break;
				}
			}
			else {
				pPre = pCur;
				pCur = pCur->right;
				if (pCur == NULL) {
					pPre->right = pNew;
					//printf("%d\n", pPre->data);
					break;
				}
			}
		}
	}
}
string preOrder(TreeNode* proot) {
	if (proot == NULL) {
		return "";
	}
	return proot->data + preOrder(proot->left) + preOrder(proot->right);
}
string inOrder(TreeNode* proot) {
	if (proot == NULL) {
		return "";
	}
	return inOrder(proot->left) + proot->data + inOrder(proot->right);
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) {
			break;
		}
		char strArr[20] = { 0 };
		scanf("%s", strArr);
		TreeNode* proot1 = NULL;
		for (int i = 0; strArr[i] != '\0'; ++i) {
			InsertBST(proot1, strArr[i]);	// - '0'   char -> int
		}
		string inOrder1 = inOrder(proot1);
		string preOrder1 = preOrder(proot1);

		for (int i = 0; i < n; ++i) {
			scanf("%s", strArr);
			TreeNode* proot2 = NULL;
			for (int j = 0; strArr[j] != '\0'; ++j) {
				InsertBST(proot2, strArr[j]);
			}
			string inOrder2 = inOrder(proot2);
			string preOrder2 = preOrder(proot2);
			if (inOrder1 == inOrder2 && preOrder1 == preOrder2) {	// 对比先序和中序序列
				printf("YES\n");	
			}
			else {
				printf("NO\n");
			}
		}

	}

	return 0;
}