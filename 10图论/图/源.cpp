#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

// A-B A-C A-D C-D
int main() {
	vector<int> graph[4];
	// A-0 B-1 C-2 D-3
	int u, v;
	u = 0, v = 1;
	graph[u].push_back(v);
	graph[v].push_back(u);

	u = 0, v = 2;
	graph[u].push_back(v);
	graph[v].push_back(u);

	u = 0, v = 3;
	graph[u].push_back(v);
	graph[v].push_back(u);

	u = 2, v = 3;
	graph[u].push_back(v);
	graph[v].push_back(u);

	return 0;
}