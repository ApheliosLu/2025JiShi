#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>	
using namespace std;

struct Block {
	int startPos;
	int blockSize;
};

int main() {
	list<Block> freeList;	// 空闲链表
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		Block block;
		scanf("%d%d", &block.startPos, &block.blockSize);
		freeList.push_back(block);
	}
	int request;
	list<Block>::iterator it;
	while (1) {
		scanf("%d", &request);
		if (request == -1) {
			break;
		}
		list<Block>::iterator toAlloc = freeList.end();	// 待分配位置 初始置空
		int curLeast = 1e9 + 1;
		for (it = freeList.begin(); it != freeList.end(); ++it) {	// 寻找合适大小的块
			if (it->blockSize == request) {
				toAlloc = it;
				break;
			}
			else if (it->blockSize > request && it->blockSize < curLeast) {	// // 找到一个最佳适应的块
				toAlloc = it;
				curLeast = it->blockSize;
			}
		}

		if (toAlloc != freeList.end()) {	// 开始分配 等于end代表没有找到合适的块
			while (toAlloc != freeList.begin()) {	// 将 toAlloc 指向的块移动到 freeList 的最前面
				Block front = freeList.front();
				freeList.pop_front();
				freeList.push_back(front);
			}
			if (toAlloc->blockSize == request) {	// while确保要分配的块位于链表的最前面，方便后续操作
				freeList.pop_front();
			}
			else {
				toAlloc->blockSize -= request;
			}
		}
	}

	for (it = freeList.begin(); it != freeList.end(); ++it) {	// 最终输出
		printf("%d %d\n", it->startPos, it->blockSize);
	}

	return 0;
}