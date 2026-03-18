#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int sum = 0;	// 记录数组的和
int diff = 0;	// 记录遍历过程中最小的差值
bool exitflag = false;	// 记录是否提前推出
void DFSFindMinDiff(vector<int> &arr,int pos,int sa) {
	if (pos == arr.size()||exitflag==true) {
		return;
	}
	
	// arr[pos] 放入a集合
	int newdiff;	// 记录当前差值
	if (2 * (sa + arr[pos]) - sum > 0) {	// 新的 A 和为 sa + arr[pos]，B 和为 sum - (sa + arr[pos])
		newdiff = 2 * (sa + arr[pos]) - sum;
	}
	else {
		newdiff = sum - 2 * (sa + arr[pos]);
	}
	if (newdiff < diff) {
		diff = newdiff;
		if (diff == 0 || diff == 1 || 2 * arr[pos] > sum) {
			exitflag = true;
		}
	}
	if (2 * (sa + arr[pos]) - sum < 0) {
		DFSFindMinDiff(arr, pos + 1, sa + arr[pos]);
	}
	// arr[pos] 不放入a集合
	DFSFindMinDiff(arr, pos + 1, sa);
}
bool compare(int lhs, int rhs) {
	return lhs > rhs;
}
int main() {
	vector<int> arr;
	int i;
	while (scanf("%d", &i) != EOF) {
		arr.push_back(i);
	}
	for (int i = 0; i < arr.size(); ++i) {
		sum += arr[i];
	}
	diff = sum;
	sort(arr.begin(), arr.end(), compare);
	DFSFindMinDiff(arr, 0, 0);
	// sa+sb=sum
	// sb-sa=diff
	int sa = (sum - diff) / 2;
	int sb = sa + diff;
	printf("%d %d\n", sb, sa);
	return 0;
}