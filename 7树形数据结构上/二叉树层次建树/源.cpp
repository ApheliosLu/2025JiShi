#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <queue>
using namespace std;

struct TreeNode {	// 树结点
	char data;
	TreeNode* left;	// 指针长度已知，可用
	TreeNode* right;
};
struct QueueNode {	// 队列结点
	TreeNode* parent;	// 队列结点指向的树结点
	bool isLeft;	// 指向的树结点的左孩子是否已插入
};
void BuildTree(TreeNode*& proot, queue<QueueNode*>& pos, char data) {
	if (data != '#') {
		// 申请一个树结点
		TreeNode* pNew = new TreeNode;
		//(*pNew).data = data;	// .优先级高于*
		pNew->data = data;	// -> 与 (*). 等价

		// 申请一个队列结点
		QueueNode* pQueueNode = new QueueNode;
		pQueueNode->parent = pNew;	// 队列节点中保存刚创建的新节点的位置
		pQueueNode->isLeft = false;
		pos.push(pQueueNode);
		if (proot == NULL) {
			proot = pNew;
		}
		else {
			QueueNode* pCur = pos.front();	// 队列队首
			if (pCur->isLeft == false) {
				pCur->parent->left = pNew;
				pCur->isLeft = true;
			}
			else {
				pCur->parent->right = pNew;
				pos.pop();
				delete pCur;
			}
		}
	}
	else {
		if (proot != NULL) {
			QueueNode* pCur = pos.front();
			if (pCur->isLeft == false) {
				pCur->parent->left = NULL;
				pCur->isLeft = true;
			}
			else {
				pCur->parent->right = NULL;
				pos.pop();
				delete pCur;
			}
		}
	}
}
void LevelOrder(TreeNode* proot) {
	queue<TreeNode*> pos;
	pos.push(proot);
	while (!pos.empty()) {
		TreeNode* pCur = pos.front();
		pos.pop();
		printf("%c", pCur->data);
		if (pCur->left != NULL) {
			pos.push(pCur->left);
		}
		if (pCur->right != NULL) {
			pos.push(pCur->right);
		}
	}
	printf("\n");
}
void PreOrder(TreeNode* proot) {
	if (proot == NULL) {
		return;
	}
	else {
		printf("%c", proot->data);
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
		printf("%c", proot->data);
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
		printf("%c", proot->data);
	}
}
int main() {
	TreeNode* proot = NULL;	// 指向根节点的指针
	char data;
	queue<QueueNode*> pos;	// 辅助队列
	while (1) {
		scanf("%c", &data);
		if (data == '\n') {
			break;
		}
		BuildTree(proot, pos, data);
	}

	LevelOrder(proot);
	PreOrder(proot);
	printf("\n");
	InOrder(proot);
	printf("\n");
	PostOrder(proot);
	printf("\n");
	return 0;
}