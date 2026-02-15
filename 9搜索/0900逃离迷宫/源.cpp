#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

struct Node {
	int x;
	int y;
	int direct;	// 四个方向
	int turn;	// 已经转弯的次数
	// 构造函数：用于创建 Node 对象时初始化成员变量
	Node(int _x, int _y, int _direct, int _turn) {
		x = _x;	// 成员变量=参数
		y = _y;
		direct = _direct;
		turn = _turn;
	}
};
bool operator<(Node lsh, Node rsh) {
	return lsh.turn > rsh.turn;	// 当 lsh.turn > rsh.turn 时返回 true，表示 lsh 小于 rsh（注意是反直觉的，因为 turn 越大反而越小）。
}
char maze[200][200];
int main() {
	int t;
	scanf("%d", &t);
	for (int idx = 0; idx < t; ++idx) {
		int m, n;
		scanf("%d%d", &m, &n);
		for (int i = 0; i < m; ++i) {
			scanf("%s", maze[i]);
		}
		int k, x1, x2, y1, y2;
		scanf("%d%d%d%d%d", &k, &y1, &x1, &y2, &x2);	// 其中 x1,x2对应列，y1, y2对应行。
		--x1; // 将编号从1到N 转成下标从0到N-1
		--x2;
		--y1;
		--y2;
		int vis[101][101][5];
		for (int i = 0; i < 101; ++i) {
			for (int j = 0; j < 101; ++j) {
				vis[i][j][1] = INT_MAX;	// 目前按照1方向到达i，j位置所经历的最小转弯次数
				vis[i][j][2] = INT_MAX;
				vis[i][j][3] = INT_MAX;
				vis[i][j][4] = INT_MAX;
			}
		}
		priority_queue<Node> tovisit;	// 使用优先队列保存待访问的邻居结点
		Node root(x1, y1, 0, 0);	// 0表示当前没有任何方向
		tovisit.push(root);
		bool isfind = false;
		while (!tovisit.empty()) {
			Node cur = tovisit.top();
			int x = cur.x, y = cur.y;
			tovisit.pop();
			if (cur.x == x2 && cur.y == y2) {
				isfind = true;
				break;
			}
			// 假设下一步走1方向
			int nextTurn = (cur.direct == 1) ? cur.turn : cur.turn + 1;	
			// 如果当前方向和下一步方向相同，则转弯次数不变（nextTurn = cur.turn）
			// 假设下一个位置在范围内，且消耗转向次数更少，则入队
			if (nextTurn <= k + 1 && x + 1 < m && maze[x + 1][y] != '*' && vis[x + 1][y][1] > nextTurn) {
				Node next(x + 1, y, 1, nextTurn);
				tovisit.push(next);
				vis[x + 1][y][1] = nextTurn;
			}

			// 假设下一步走2方向
			nextTurn = (cur.direct == 2) ? cur.turn : cur.turn + 1;
			// 假设下一个位置在范围内，且消耗转向次数更少，则入队
			if (nextTurn <= k + 1 && x - 1 >= 0 && maze[x - 1][y] != '*' && vis[x - 1][y][2] > nextTurn) {
				Node next(x - 1, y, 2, nextTurn);
				tovisit.push(next);
				vis[x - 1][y][2] = nextTurn;
			}

			// 假设下一步走3方向
			nextTurn = (cur.direct == 3) ? cur.turn : cur.turn + 1;
			// 假设下一个位置在范围内，且消耗转向次数更少，则入队
			if (nextTurn <= k + 1 && y + 1 < n && maze[x][y + 1] != '*' && vis[x][y + 1][3] > nextTurn) {
				Node next(x, y + 1, 3, nextTurn);
				tovisit.push(next);
				vis[x][y + 1][3] = nextTurn;
			}

			// 假设下一步走4方向
			nextTurn = (cur.direct == 4) ? cur.turn : cur.turn + 1;
			// 假设下一个位置在范围内，且消耗转向次数更少，则入队
			if (nextTurn <= k + 1 && y - 1 >= 0 && maze[x][y - 1] != '*' && vis[x][y - 1][4] > nextTurn) {
				Node next(x, y - 1, 4, nextTurn);
				tovisit.push(next);
				vis[x][y - 1][4] = nextTurn;
			}
		}
		if (isfind) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}

	return 0;
}