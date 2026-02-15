#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
void Partition(string str, vector<int>& vec1, vector<int>& vec2, vector<int>& vec3) {
	int i;
	for (i = 0; i < str.size(); ++i) {
		if (str[i] >= 'a' && str[i] <= 'i') {
			vec1.push_back(i);
		}
		else if (str[i] >= 'j' && str[i] <= 'r') {
			vec2.push_back(i);
		}
		else {
			vec3.push_back(i);
		}
	}
}
void RightRotate(string &str,vector<int> &vec,int offset) {
	vector<char> tmp;
	if (vec.size() != 0 && offset > vec.size()) {
		offset = offset % vec.size();
	}
	for (int i = vec.size() - offset; i < vec.size(); ++i) {
		tmp.push_back(str[vec[i]]);
	}
	for (int i = vec.size() - offset - 1; i >= 0; --i) {
		str[vec[i + offset]] = str[vec[i]];
	}
	for (int i = 0; i < tmp.size(); ++i) {
		str[vec[i]] = tmp[i];
	}
}
int main() {
	// t h e _ q u i c k _ b r o w n _ f o x
	// 3 1 1 3 2 3 1 1 2 3 1 2 2 3 2 3 1 2 3
	//   h e       i c     b           f    
	//   i c       b f     h           e
	//         q       k     r o   n     o  
	//         o       n     o q   k     r
	// t     _   u       _       w   _     x
	// _     u   _       w       _   x     t
	//


	//   i c       b f     h           e
	//         o       n     o q   k     r
	// _     u   _       w       _   x     t
	// _ i c u o _ b f n w h o q _ k x e r t

	// 分组 右旋
	string str;
	int k1, k2, k3;
	while (scanf("%d%d%d", &k1, &k2, &k3) != EOF) {
		if (k1 == 0 && k2 == 0 && k3 == 0) {
			break;
		}
		char arr[1000] = { 0 };
		scanf("%s", arr);
		str = arr;
		vector<int> vec1, vec2, vec3;
		// vec1 存储1分组在str1中的下标
		Partition(str, vec1, vec2, vec3);

		RightRotate(str, vec1, k1);
		RightRotate(str, vec2, k2);
		RightRotate(str, vec3, k3);

		printf("%s\n", str.c_str());
	}
	return 0;
}