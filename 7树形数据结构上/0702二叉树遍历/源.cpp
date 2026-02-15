#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
using namespace std;

struct TreeNode {
	char data;
	TreeNode* left;
	TreeNode* right;
};
TreeNode* RecursiveBuildTree(int& i, char str[]) {	// 构建树
	char ch = str[i];
	++i;
	if (ch == '#') {
		return NULL;
	}
	else {
		TreeNode* pNew = new TreeNode;
		pNew->data = ch;
		pNew->left = RecursiveBuildTree(i, str);
		pNew->right = RecursiveBuildTree(i, str);
		return pNew;	// 返回子树根节点
	}
}
void InOrder(TreeNode* proot) {
	if (proot == NULL) {
		return;
	}
	else {
		InOrder(proot->left);
		printf("%c ", proot->data);
		InOrder(proot->right);
	}
}
int main() {
	char str[1000];
	while (scanf("%s", str) != EOF) {
		int i = 0;
		TreeNode* proot = RecursiveBuildTree(i, str);
		InOrder(proot);
		printf("\n");
	}
	return 0;
}