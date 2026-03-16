#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main() {
	int m, n;
	while (1) {
		scanf("%d%d", &m, &n);
		if (m == 0 && n == 0) {
			break;
		}

		int i = 1;	// 层数
		int begin_level;	// 存储子树的根在第几层
		int final_level;	// 大树总共有几层
		// 2^(i-1) ~ 2^i-1 每一层的下标范围
		// 1<<i == 2^i
		while (1) {
			if (m >= 1 << (i - 1) && m < 1 << i) {
				begin_level = i;
			}// 子树根在第i层
			if (n >= 1 << (i - 1) && n < 1 << i) {
				final_level = i;
				break;	// 大数在第i层
			}
			++i;
		}
		// 	得到第 final_level 层上该子树的最左节点 left_side 和最右节点 right_side。
		int left_side = m;
		int right_side = m;
		for (i = begin_level; i < final_level; ++i) {
			left_side = 2 * left_side;	// 最下面的左右孩子的下标
			right_side = 2 * right_side + 1;
		}
		int treeNUm;

		// left_side>n 说明 实际的最左最右孩子在倒数第2层 子树是一颗从begin_level~final_level-1的满二叉树 3 11
		// 三种情况
		if(left_side>n){	
			treeNUm = (1 << (final_level - begin_level)) - 1;	// 3 11
		}
		else if(n<=right_side) {
			treeNUm = (1 << (final_level - begin_level)) - 1;	// 3 12
			treeNUm += n - left_side + 1;
		}
		else {
			treeNUm = (1 << (final_level - begin_level+1)) - 1;	// 2 15
		}
		printf("%d\n", treeNUm);
	}
	return 0;
}