#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");  // 设置本地化环境，支持宽字符

    wchar_t str[1024];  // 宽字符数组
    wchar_t pattern[30][30] = { 0 };  // 宽字符二维数组

    while (wscanf(L"%ls", str) != EOF) {
        int N = wcslen(str);  // 宽字符长度
        int n1, n2, n3;

        // 枚举算出 n1、n2、n3 的合理值
        for (n2 = 3; n2 <= N; ++n2) {
            if ((N + 2 - n2) % 2 == 0) {
                n1 = (N + 2 - n2) / 2;
                if (n1 <= n2) {
                    n3 = n1;
                    break;
                }
            }
        }

        // 初始化 pattern 数组
        for (int i = 0; i < 29; ++i) {
            for (int j = 0; j < 29; ++j) {
                pattern[i][j] = L' ';  // 宽字符空格
            }
        }

        int x = 0, y = 0;
        for (int i = 0; i < N; ++i) {
            if (i < n1 - 1) {  // 向下
                pattern[x][y] = str[i];
                ++x;
            }
            else if (i < n1 + n2 - 2) {  // 向右
                pattern[x][y] = str[i];
                ++y;
            }
            else {  // 向上
                pattern[x][y] = str[i];
                --x;
            }
        }

        // 输出 pattern
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                wprintf(L"%lc", pattern[i][j]);  // 逐字符输出宽字符
            }
            wprintf(L"\n");
        }
    }

    return 0;
}