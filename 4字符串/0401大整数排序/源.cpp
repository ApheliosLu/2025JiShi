#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(string lhs, string rhs) {
	if (lhs.size() < rhs.size()) {
		return true;
	}
	else if(lhs.size()==rhs.size()){
		for (int i = 0; i < lhs.size(); ++i) {
			if (lhs[i] < rhs[i]) {
				return true;
			}
			else if (lhs[i] > rhs[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}
int main() {
	int N;
	scanf("%d", &N);
	vector<string> vec(N);
	for (int i = 0; i < N; ++i) {
		char strArr[1100];
		scanf("%s", strArr);
		vec[i] = strArr;
	}
	sort(vec.begin(), vec.end(), compare);
	for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it) {
		printf("%s\n", it->c_str());
	}
	return 0;
}