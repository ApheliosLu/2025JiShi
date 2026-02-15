#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 30;
int children[MAXN];

int Generation(int x, int y) {
	int level;
	level = 0;
	int a = x;
	while (children[a] != a) {
		a = children[a];
		level++;
		if (a == y) {
			return level;	// 返回y相对x的层次 假设y是x的儿孙辈
		}
	}
	
	level = 0;
	int b = y;
	while (children[b] != b) {
		b = children[b];
		level--;
		if (b == x) {
			return level;	// 假设x是y的儿孙辈
		}
	}

	return 0;
}

string Relationship(int level) {
	string answer;
	if (level == 0) {
		answer = "-";
	}
	else if(level==1){
		answer = "parent";
	}
	else if (level == 2) {
		answer = "grandparent";
	}
	else if (level >2) {
		for (int j = 0; j < level - 2; ++j) {
			answer += "great-";
		}
		answer += "grandparent";
	}
	else if (level == -1) {
		answer = "child";
	}
	else if (level == -2) {
		answer = "grandchild";
	}
	else if (level <- 2) {
		for (int j = 0; j <-2-level; ++j) {
			answer += "great-";
		}
		answer += "grandchild";
	}
	return answer;
}
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < MAXN; ++i) {
			children[i] = i;
		}
		for (int i = 0; i < n; ++i) {
			char child, father, mother;
			cin >> child >> father >> mother;
			if (father - 'A' != '-') {	// 父母信息齐全
				children[father - 'A'] = child - 'A';
			}
			if (mother - 'A' != '-') {
				children[mother - 'A'] = child - 'A';
			}
		}
		for (int i = 0; i < m; ++i) {
			char guy1, guy2;
			cin >> guy1 >> guy2;
			int level = Generation(guy1 - 'A', guy2 - 'A');
			cout << Relationship(level) << endl;
		}
	}
	return 0;
}