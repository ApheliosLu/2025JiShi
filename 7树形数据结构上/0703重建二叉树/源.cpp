#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
	char data;
	TreeNode* left;
	TreeNode* right;
};
TreeNode* Rebuild(string PreOrder,string InOrder) {
	if (PreOrder.size() == 0) {
		return NULL;
	}
	else {
		char rootdata = PreOrder[0];
		TreeNode* pNew = new TreeNode;
		pNew->data = rootdata;
		int pos = InOrder.find(rootdata);
		pNew->left = Rebuild(PreOrder.substr(1, pos),InOrder.substr(0, pos));	// ×ó×ÓÊ÷
		pNew->right = Rebuild(PreOrder.substr(pos + 1), InOrder.substr(pos + 1)); // ÓÒ×ÓÊ÷
		return pNew;
	}
}
void PostOrder(TreeNode* proot) {
	if (proot == NULL) {
		return;
	}
	else {
		PostOrder(proot->left);
		PostOrder(proot->right);
		printf("%c", proot->data);
	}
}
int main() {
	//unique_ptr<int> uptr(new int(10));
	char PreOrder[30];
	char InOrder[30];
	while (scanf("%s%s", PreOrder, InOrder) != EOF) {
		TreeNode* proot;
		proot = Rebuild(PreOrder, InOrder);
		PostOrder(proot);
		printf("\n");
	}

	return 0;
}