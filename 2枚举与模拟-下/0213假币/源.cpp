#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    map<int, int> equal;
    map<int, int> light;
    map<int, int> heavy;
    for (int i = 0; i < k; ++i) {
        int p;
        scanf("%d", &p);
        int set1[600], set2[600];
        for (int j = 0; j < p; ++j) {
            scanf("%d", &set1[j]);
        }
        for (int j = 0; j < p; ++j) {
            scanf("%d", &set2[j]);
        }
        char res[3];
        scanf("%s", res);
        if (res[0] == '=') {
            for (int j = 0; j < p; ++j) {
                equal[set1[j]] = 1; // 加入equal集合
                equal[set2[j]] = 1;
            }
        }
        else {
            if (res[0] == '<') {    // 左轻右重
                for (int j = 0; j < p; ++j) {
                    light[set1[j]] = 1;
                    heavy[set2[j]] = 1;
                }
            }
            else { // '>'
                for (int j = 0; j < p; ++j) {
                    heavy[set1[j]] = 1;
                    light[set2[j]] = 1;
                }
            }

            map<int, int> in; //补集
            for (int j = 0; j < p; ++j) {   // 测试的加入
                in[set1[j]] = 1;
                in[set2[j]] = 1;
            }
            for (int j = 1; j <= n; ++j) {  // 未测试的为真
                if (in[j] != 1) {
                    equal[j] = 1;
                }
            }
        }
    }

    int count = 0;
    int num;
    for (int i = 1; i <= n; ++i) {
        if (light[i] == 1 && heavy[i] == 1) {   // 又轻又重 矛盾 为真
            equal[i] = 1;
        }
        if (equal[i] == 1) {
            ++count;
        }
        else {
            num = i;    // 假币编号
        }

    }

    if (count == n - 1) {
        printf("%d\n", num);
    }
    else {
        printf("0\n");
    }
    return 0;
}
