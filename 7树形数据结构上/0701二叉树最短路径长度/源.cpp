#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
using namespace std;

// 构造树 -> 找到节点到根的路径 -> 找交点
struct TreeNode {
	int num;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
};
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<TreeNode*> nodeArr(n + 1);
		for (int j = 1; j <= n; ++j) {
			nodeArr[j] = new TreeNode;
			nodeArr[j]->num = j;
		}
		nodeArr[1]->parent = NULL;
		for (int j = 1; j <= n; ++j) {
			int left, right;
			scanf("%d%d", &left, &right);
			if (left != -1) {
				nodeArr[j]->left = nodeArr[left];
				nodeArr[left]->parent = nodeArr[j];
			}
			else {
				nodeArr[j]->left = NULL;
			}
			if (right != -1) {
				nodeArr[j]->right = nodeArr[right];
				nodeArr[right]->parent = nodeArr[j];
			}
			else {
				nodeArr[j]->right = NULL;
			}
		}
		int lhs, rhs;
		for (int j = 0; j < m; ++j) {
			scanf("%d%d", &lhs, &rhs);
			vector<int> lvec;
			TreeNode* p = nodeArr[lhs];
			while (p != NULL) {
				lvec.push_back(p->num);
				p = p->parent;
			}
			vector<int> rvec;	// 两个结点分别到根的路径
			p = nodeArr[rhs];
			while (p != NULL) {
				rvec.push_back(p->num);
				p = p->parent;
			}
			int l = lvec.size() - 1;
			int r = rvec.size() - 1;
			while (true) {	// lr为两个结点分别到最近公共节点的前一个结点的距离
				if (l < 0 || r < 0||lvec[l]!=rvec[r]) {
					break;
				}
				--l;
				--r;
			}
			printf("%d\n", l + r + 2);
		}
	}
	return 0;
}