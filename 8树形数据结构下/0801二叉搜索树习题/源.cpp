#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
using namespace std;

struct TreeNode {
    int father;
    int left;
    int right;
};
// 为了提前找到父亲节点的位置，需要找到离data最近的位置
// 假设bst当中的当前数据已经有序，即 a[0] < a[1] < .. < a[i] < a[i+1] < ...
// 则 a[i] 和 a[i+1] 必定为父子关系（反证法容易证明）。
// 要么 a[i]左孩子&&a[i+1]父亲；要么 a[i]父亲&&a[i+1]右孩子
// 若data是最新的数据，且满足 a[i] < data < a[i+1]，则 data应该是左孩子的右孩子 或者 是右孩子的左孩子，不会直接和父亲相连
map<int, int> dataToLevel; // 使用map存储树的层次，方便判断根据树的深度，可以判断相邻节点谁是父亲谁是孩子
TreeNode arr[100001]; // 使用顺序存储节约空间
void InsertBST(int i, int data) {
    arr[data].left = -1;
    arr[data].right = -1; //左右孩子均不存在
    if (i == 1) {
        arr[data].father = 0; //根
        dataToLevel[data] = 1;
    }
    else {
        int father;
        map<int, int>::iterator it1 = dataToLevel.upper_bound(data);    // 查找第一个大于给定值的元素位置
        if (it1 == dataToLevel.begin()) {
            father = it1->first;
        }
        else if (it1 == dataToLevel.end()) {    // 没有比 3 大的节点，所以 it1 == dataToLevel.end()
            --it1;
            father = it1->first;
        }
        else {
            map<int, int>::iterator it2 = it1;
            --it1;
            if (it2->second > it1->second) {    // 选择深度更大的节点作为父节点
                father = it2->first;
            }
            else {
                father = it1->first;
            }
        }

        arr[data].father = father;
        dataToLevel[data] = dataToLevel[father] + 1;
        if (father < data) {
            arr[father].right = data;
        }
        else {
            arr[father].left = data;
        }
    }
}
int main() {
	int n;
	scanf("%d", &n);
    int data;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &data);
        InsertBST(i, data);
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", arr[i].father);
    }
    printf("\n");
	return 0;
}