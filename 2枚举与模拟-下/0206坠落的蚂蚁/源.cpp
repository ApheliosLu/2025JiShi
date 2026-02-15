#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>	
#include <algorithm>	// sort排序所需头文件
using namespace std;

/*
	// 题目提示
	// 所以的蚂蚁分为两类 A和普通蚂蚁
	// 1 两只普通蚂蚁发生碰撞时，可以等价双方直接互相穿越。
	//   因此，A左边向走的普通蚂蚁(LL)和A右边向右走(RR)的普通蚂蚁对A不产生影响。
	//   A最终的方向取决于左边向右转(LR)和A右边向左走(RL)的相对数量
	// 2 如果只有一个普通蚂蚁和A，普通蚂蚁碰撞了静止的A导致A下落
	//   那么A的下落时间等于不发生碰撞情况下普通蚂蚁的原本下落时间
	// 记LR的数量为LRN，RL的数量为RLN
	// 如果 LRN == RLN 则 A不会掉下
	// 如果 LRN > RLN 则 第RLN+1个LR蚂蚁会碰撞A导致A下落，其余LR蚂蚁不和A碰撞
	// 如果 LRN < RLN 则 第LRN+1个RL蚂蚁会碰撞A导致A下落，其余RL蚂蚁不和A碰撞
*/

struct Ant {
	int pos;
	int velocity;
};

int main() {
	int n;
	scanf("%d", &n);
	Ant ant[100];
	int Apos;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &ant[i].pos, &ant[i].velocity);
		if (ant[i].velocity == 0) {
			Apos = ant[i].pos;
		}
	}
	// 找到所有的LR和RL
	int LR[100], RL[100];   // 记录所有LR和RL蚂蚁的位置
	int LRN = 0, RLN = 0;
	for (int i = 0; i < n; ++i) {
		if (ant[i].pos < Apos && ant[i].velocity>0) {
			LR[LRN] = ant[i].pos;
			++LRN;
		}
		if (ant[i].pos > Apos && ant[i].velocity < 0) {
			RL[RLN] = ant[i].pos;
			++RLN;
		}
	}
	if (LRN == RLN) {
		printf("Cannot fall!\n");
	}
	else {
		// 按照在木棒上的位置排序
		sort(LR, LR + LRN); // 靠左的下标为0
		sort(RL, RL + RLN); // 靠右的下标为RLN-1
		// 刚开始的蚂蚁分布大致如下
		// LR[0] --> LR[1] --> LR[2] --> ... -> LR[LRN-1] --> A <-- RL[0] <-- RL[1] ... <-- RL[RLN-1]
		if (LRN > RLN) {
			// LR[LRN-1]匹配RL[0] LR[LRN-2]匹配RL[1] ... LR[LRN-RLN]匹配RL[RLN-1]
			// 多出来的第一个LR是LR[LRN-RLN-1] 从左往右走
			printf("%d\n", 100 - LR[LRN - RLN - 1]);
		}
		else {
			// LR[LRN-1]匹配RL[0] LR[LRN-2]匹配RL[1] ... LR[0]匹配RL[LRN-1]
			// 多出来的第一个RL是RL[LRN] 从右往左
			printf("%d\n", RL[LRN]);
		}
	}
	return 0;
}