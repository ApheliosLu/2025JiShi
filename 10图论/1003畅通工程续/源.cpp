// 最短路径 Dijkstra算法的基本实现
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {	// 边类型
	int u;
	int v;
	int weight;	// 边权重
	Edge(int _u, int _v, int _weight) {
		u = _u;
		v = _v;
		weight = _weight;
	}
};

vector<Edge> graph[300];	// 邻接表法的图

struct PQueueNode {	// 优先队列结点
	int u;
	int distance;	// 距离起点距离
	PQueueNode(int _u, int _distance) {
		u = _u;
		distance = _distance;
	}
};

bool operator< (PQueueNode lhs, PQueueNode rhs) {
	return lhs.distance > rhs.distance;	// 实现小根堆
}

// Dijkstra 获取最短路径
int Dijkstra(int s, int t) {
	priority_queue<PQueueNode> pqueue;
	int distance[300];
	bool isVisited[300];
	for (int i = 0; i < 300; ++i) {
		distance[i] = -1;	// 初始到不了 -1代表+∞
		isVisited[i] = false;
	}
	distance[s] = 0;	// 起点到自身距离为0
	PQueueNode qnode(s, 0);	
	pqueue.push(qnode);	// 将起点压入优先队列
	while (pqueue.empty() == false) {
		int u = pqueue.top().u;
		pqueue.pop();
		if (isVisited[u] == true) {
			continue;	// 避免重复访问
		}
		isVisited[u] = true;
		for (int i = 0; i < graph[u].size(); ++i) {	// 依次访问u的邻居
			int v = graph[u][i].v;
			int weight = graph[u][i].weight;

			if (distance[v] == -1 ||
				distance[v] > distance[u] + weight) {
				distance[v] = distance[u] + weight;	// 更新最短路径
				PQueueNode next(v, distance[v]);
				pqueue.push(next);	// 邻居加入优先队列
			}
		}
	}
	return distance[t];	// 返回终点距离
}

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; ++i) {
			graph[i].clear();	// 每组数据初始化
		}
		for (int i = 0; i < m; ++i) {
			int u, v, weight;
			scanf("%d%d%d", &u, &v, &weight);
			Edge e1(u, v, weight);
			graph[u].push_back(e1);
			Edge e2(v, u, weight);	// 无向图 存储两次
			graph[v].push_back(e2);
		}	// 邻接表读取完毕

		int s, t;
		scanf("%d%d", &s, &t);	// 读取起点终点
		printf("%d\n", Dijkstra(s, t));
	}
	return 0;
}