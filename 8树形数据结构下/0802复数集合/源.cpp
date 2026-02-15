#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

struct Complex {
	int re;
	int im;
	// 构造函数 简化初始化过程
	// 构造函数在类的内部，名称和类名一致，没有返回值
	Complex(int _re, int _im) {
		re = _re;
		im = _im;
	}
};
// 自定义 < 运算符，运算符重载
// 重载 < 原本的小于号 有两个参数 返回值是bool
// 自定义一个函数 参数数量不变，返回值类型不变，名字是operator 运算符
// 若 a<b 返回 true 大根堆
// 若 a<b 返回 false 小根堆
bool operator <(Complex lhs, Complex  rhs) {
	if (lhs.re * lhs.re + lhs.im * lhs.im < rhs.re * rhs.re + rhs.im * rhs.im) {
		return true;	// 保持大根堆
	}
	else {
		return false;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	priority_queue<Complex> pqueue;
	for (int i = 0; i < n; ++i) {
		char actionArr[30];
		scanf("%s", actionArr);
		string action = actionArr;
		if (action == "Pop") {
			if (pqueue.empty()) {
				printf("empty\n");
			}
			else {
				printf("%d+i%d\n", pqueue.top().re, pqueue.top().im);
				pqueue.pop();
				printf("SIZE = %d\n", pqueue.size());
			}
		}
		else if (action == "Insert") {
			int re, im;
			scanf("%d+i%d", &re, &im);	// 格式化输入
			//Complex c;
			//c.re = re;
			//c.im = im;
			Complex c(re, im);	// 等价于上面三行的初始化
			pqueue.push(c);
			printf("SIZE = %d\n", pqueue.size());
		}
	}

	return 0;
}