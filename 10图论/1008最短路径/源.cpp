#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct BigInteger {
	int digit[10000];	// 这里自定义了一个大整数类型，并且重载了 +-*/%赋值 等运算符
	int length;
	BigInteger();	// 默认
	BigInteger(int x);	// 从整数到大整数
	BigInteger(string str);	// 从字符串到大整数
	BigInteger(const BigInteger& b);	// 从一个大整数到另一个大整数

	BigInteger operator=(int x);
	BigInteger operator=(string x);
	BigInteger operator=(const BigInteger& b);

	bool operator<(const BigInteger& b);
	bool operator<=(const BigInteger& b);
	bool operator==(const BigInteger& b);

	BigInteger operator+(const BigInteger& b);	// 运算符重载
	BigInteger operator-(const BigInteger& b);
	BigInteger operator*(const BigInteger& b);
	BigInteger operator/(const BigInteger& b);
	BigInteger operator%(const BigInteger& b);

	// C++ 中 >> 和 << 原本是位运算中的移位运算符，但在这里它们被重载为输入输出运算符了
	friend istream& operator>>(istream& in, BigInteger& b);	// friend 授予非成员函数或其他类访问某个类的私有(private)和保护(protected)成员的权限。
	friend ostream& operator<<(istream& out, const BigInteger& b);
};

istream& operator>>(istream& in, BigInteger& b) {
	string str;
	in >> str;
	b = str;	// 调用 BigInteger 的 string 构造函数
	return in;	// 返回输入流（支持链式调用，如 cin >> a >> b）
}

ostream& operator<<(ostream& out, const BigInteger& b) {
	for (int i = b.length - 1; i >= 0; --i) {
		out << b.digit[i];	 // 逆序输出（因为存储时是低位在前）
	}
	return out;
}

BigInteger::BigInteger() {
	memset(digit, 0, sizeof(digit));
	length = 0;
}

BigInteger::BigInteger(int x) {
	// 数字是以逆序（低位在前，高位在后）的方式存储在 digit 数组中的。
	memset(digit, 0, sizeof(digit));
	length = 0;
	if (x == 0) {
		digit[length++] = x;
	}
	while (x != 0) {
		digit[length++] = x % 10;	// 取最低位存入 digit[0], digit[1], ...
		x /= 10;	// 去掉最低位
	}
}

BigInteger::BigInteger(string str) {
	memset(digit, 0, sizeof(digit));
	length = str.size();
	for (int i = 0; i < length; ++i) {
		digit[i] = str[length - i - 1] - '0';
	}
}

BigInteger::BigInteger(const BigInteger& b) {
	memset(digit, 0, sizeof(digit));
	length = b.length;
	for (int i = 0; i < length; ++i) {
		digit[i] = b.digit[i];
	}
}

BigInteger BigInteger::operator=(int x) {
	memset(digit, 0, sizeof(digit));
	length = 0;
	if (x == 0) {
		digit[length++] = x;
	}
	while (x != 0) {
		digit[length++] = x % 10;
		x /= 10;
	}
	return *this;
}

BigInteger BigInteger::operator=(string str) {
	memset(digit, 0, sizeof(digit));
	length = str.size();
	for (int i = 0; i < length; ++i) {
		digit[i] = str[length - i - 1] - '0';
	}
	return *this;
}

BigInteger BigInteger::operator=(const BigInteger& b) {
	memset(digit, 0, sizeof(digit));
	length = b.length;
	for (int i = 0; i < length; ++i) {
		digit[i] = b.digit[i];
	}
	return *this;	// operator= 中，this 指向被赋值的对象（即 = 左边的对象）
}

bool BigInteger::operator<(const BigInteger& b) {
	if (length < b.length) {
		return true;
	}else if (b.length < length) {
		return false;
	}else {
		for (int i = length - 1; i >= 0; i--) {
			if (digit[i] == b.digit[i]) {
				continue;
			}
			else {
				return digit[i] < b.digit[i];
			}
		}
	}
	return false;
}

bool BigInteger::operator<=(const BigInteger& b) {
	if (length < b.length) {
		return true;
	}
	else if (b.length < length) {
		return false;
	}
	else {
		for (int i = length - 1; i >= 0; i--) {
			if (digit[i] == b.digit[i]) {
				continue;
			}else {
				return digit[i] < b.digit[i];
			}
		}
	}
	return true;
}

bool BigInteger::operator==(const BigInteger& b) {
	if (length != b.length) {
		return false;
	}else {
		for (int i = length - 1; i >= 0; i--) {
			if (digit[i] != b.digit[i]) {
				return false;
			}
		}
	}
	return true;
}

BigInteger BigInteger::operator+(const BigInteger& b) {
	BigInteger answer;
	int carry = 0;
	for (int i = 0; i < length || i < b.length; ++i) {
		int current = carry + digit[i] + b.digit[i];
		carry = current / 10;
		answer.digit[answer.length++] = current % 10;
	}
	if (carry != 0) {
		answer.digit[answer.length++] = carry;
	}
	return answer;
}

BigInteger BigInteger::operator-(const BigInteger& b) {
	BigInteger answer;
	int carry = 0;
	for (int i = 0; i < length ; ++i) {
		int current = digit[i]-b.digit[i]-carry;
		if (current < 0) {
			current += 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		answer.digit[answer.length++] = current;
	}
	while (answer.digit[answer.length - 1] == 0 && answer.length > 1) {	// 去除前导零
		answer.length--;
	}
	return answer;
}

BigInteger BigInteger::operator*(const BigInteger& b) {
	BigInteger answer;
	answer.length = length + b.length;
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < b.length; ++j) {
			answer.digit[i + j] += digit[i] * b.digit[j];
		}
	}
	for (int i = 0; i < answer.length; ++i) {	// 处理进位
		answer.digit[i + 1] += answer.digit[i] / 10;
		answer.digit[i] %= 10;
	}
	while (answer.digit[answer.length - 1] == 0 && answer.length > 1) {
		answer.length--;
	}
	return answer;
}

BigInteger BigInteger::operator/(const BigInteger& b) {
	BigInteger answer;
	answer.length = length ;
	BigInteger remainder = 0;
	BigInteger temp = b;
	for (int i = length - 1; i>=0 ; --i) {
		if (!(remainder.length == 1 && remainder.digit[0] == 0)) {	// 检查当前的余数(remainder)是否不为零
			for (int j = remainder.length - 1; j >= 0; --j) {
				remainder.digit[j + 1] = remainder.digit[j];
			}
			remainder.length++;
		}
		remainder.digit[0] = digit[i];
		while (temp <= remainder) {
			remainder = remainder - temp;
			answer.digit[i]++;
		}
	}
	while (answer.digit[answer.length - 1] == 0 && answer.length > 1) {
		answer.length--;
	}
	return answer;	// 商
}

BigInteger BigInteger::operator%(const BigInteger& b) {
	BigInteger remainder = 0;
	BigInteger temp = b;
	for (int i = length - 1; i >= 0; --i) {
		if (!(remainder.length == 1 && remainder.digit[0] == 0)) {
			for (int j = remainder.length - 1; j >= 0; --j) {	// // 将remainder左移1位(×10)
				remainder.digit[j + 1] = remainder.digit[j];
			}
			remainder.length++;
		}
		remainder.digit[0] = digit[i];
		while (temp <= remainder) {
			remainder = remainder - temp;
		}
	}
	while (temp<=remainder) {
		remainder=remainder-temp;
	}
	return remainder;	// 余数
}

const int MAXN = 100 + 10;
const int MOD = 1e5;

struct Edge {
	int to;	// 终点
	BigInteger length;	// 长度
	Edge(int t,BigInteger l):to(t),length(l){}
};

struct Point{
	int number;	// 点的编号
	BigInteger distance;	// 源点到该点距离
	Point(int n,BigInteger d):number(n),distance(d){}
	bool operator<(Point p)const {
		return p.distance < distance;	// 距离小的优先级高
	}
};

vector<Edge> graph[MAXN];	// 邻接表实现的图
BigInteger minDistance[MAXN];	// 源点到各点最短距离

void Dijkstra(int start) {
	minDistance[start] = 0;
	priority_queue<Point> myPriorityQueue;
	myPriorityQueue.push(Point(start, minDistance[start]));

	while (!myPriorityQueue.empty()) {
		int u = myPriorityQueue.top().number;	// 离源点最近的点
		myPriorityQueue.pop();
		for (int i = 0; i < graph[u].size(); ++i) {	// 依次访问u的邻居
			int v = graph[u][i].to;
			BigInteger l = graph[u][i].length;

			if (minDistance[u]+l<minDistance[v]) {
				minDistance[v] = minDistance[u] + l;
				myPriorityQueue.push(Point(v, minDistance[v]));
			}
		}
	}
	return;
}

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(graph, 0, sizeof(graph));
		BigInteger length = 1;
		for (int i = 0; i < m; ++i) {
			int from, to;
			scanf("%d%d", &from, &to);
			graph[from].push_back(Edge(to, length));
			graph[to].push_back(Edge(from, length));
			length = length * BigInteger(2);
		}
		BigInteger INF = length;
		fill(minDistance, minDistance + n, INF);
		Dijkstra(0);
		for (int i = 1; i < n; ++i) {
			if (minDistance[i] == INF) {
				cout << -1 << endl;
			}
			else {
				cout << minDistance[i] % MOD << endl;
			}
		}
	}
}