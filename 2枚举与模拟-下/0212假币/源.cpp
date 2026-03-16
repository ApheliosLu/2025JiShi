#define _CRT_SECURE_NO_WARNINGS
#include <map>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

int main() {
    char set1[10], set2[10], resultArr[10];
    map<char, int> light;   // 可能是轻的硬币
    map<char, int> equal;    // 一定是真币（因为在天平平衡时出现）
    map<char, int> heavy;  // 可能是重的硬币
    for (int i = 0; i < 3; ++i) {
        scanf("%s%s%s", set1, set2, resultArr);
        string result = resultArr;  
        if (result == "even") {
            for (int i = 0; i < strlen(set1); ++i) {
                equal[set1[i]] = 1;
                equal[set2[i]] = 1;
            }
        }
        else if (result == "up") {
            map<char, int> in;
            //in集合用来处理补集的逻辑 如果 set1和set2 不等，则剩余的所有都是真币
            for (int i = 0; i < strlen(set1); ++i) {
                heavy[set1[i]] = 1; // 左重右轻
                in[set1[i]] = 1;    //  in 集合记录参与本次称重的硬币（即左边和右边的硬币）
                light[set2[i]] = 1;
                in[set2[i]] = 1;
            }
            for (char ch = 'A'; ch <= 'L'; ++ch) {  // 未参与称重的硬币（不在 in 集合中的）一定是真币，加入 equal 集合
                if (in[ch] != 1) {
                    equal[ch] = 1;
                }
            }
        }
        else {
            map<char, int> in;
            for (int i = 0; i < strlen(set1); ++i) {
                light[set1[i]] = 1;
                in[set1[i]] = 1;
                heavy[set2[i]] = 1;
                in[set2[i]] = 1;
            }
            for (char ch = 'A'; ch <= 'L'; ++ch) {
                if (in[ch] != 1) {
                    equal[ch] = 1;
                }
            }
        }
    }
    // ABCD EFGH IJKL
    for (char ch = 'A'; ch <= 'L'; ++ch) {
        if (equal[ch] == 1) {
            // 如果某个币某次出现了相等的结果  一个硬币在 equal 集合中（即确定是真币），则从 light 和 heavy 中移除
            light[ch] = 0;
            heavy[ch] = 0;
        }
        else if (light[ch] == 1 && heavy[ch] == 1) {
            // 如果某个币既在左边又在右边    一个硬币同时在 light 和 heavy 中（矛盾，不可能既轻又重），则将其从两个集合中移除
            light[ch] = 0;
            heavy[ch] = 0;
            equal[ch] = 0;
        }
    }
    for (map<char, int>::iterator it = light.begin(); it != light.end(); ++it) {
        if (it->second == 1) {
            printf("%c is the counterfeit coin and it is light.\n", it->first);
        }
    }
    for (map<char, int>::iterator it = heavy.begin(); it != heavy.end(); ++it) {
        if (it->second == 1) {
            printf("%c is the counterfeit coin and it is heavy.\n", it->first);
        }
    }
    return 0;
}
