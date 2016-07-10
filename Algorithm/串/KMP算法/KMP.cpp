//
// 时间复杂度: O(M+N)
// Created by andy on 16/6/19.
//

#include <iostream>
using namespace std;

// 获取字符串 T 的 next数组
void getNext(char T[], int *next)
{
    int i = 1;      // 后缀       (注意,整个过程中i>j)
    int j = 0;      // 前缀
    int tLength = T[0] - '0';       // '6' - '0' = 6
    next[1] = 0;    // 固定数
    cout << "i: " << next[i]  << " ,";
    while (i < tLength)   // T[0]中存放的字符串的长度
    {
        if (j == 0 || T[i] == T[j])
        {
            ++i;
            ++j;
            next[i] = j;
            cout << "i: " << next[i]  << " ,";
        }
        else                    // 如果遇到不相等
        {
            j = next[j];        // 一定要理解这里( 如果没找到则j回溯,而i整个过程中不回溯)
        }
    }
    cout << "" << endl;
}

// 得到索引位置
int indexKMP(char S[], char T[], int pos)
{
    int i = pos;                // 主串从POS位置开始匹配
    int j = 1;                  // j用于子串T中当前位置下标
    int next[255];
    int sLength = S[0] - '0';   // 一定在注意字符串大小(是ASCII码,必须转化为数字)
    int tLength = T[0] - '0';
    cout << "sLength: " << sLength <<endl;
    cout << "tLength: " << tLength <<endl;
    getNext(T, next);           // 获取子串的next数组

    while (i <= sLength && j <= tLength)
    {
        if (j == 0 || S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    if (j > tLength) return i - tLength;
    else return 0;
}

// 测试过程中 string1 和 string2 中第一个字符为字符串长度
int main()
{
    int next[255];
    char string1[] = "9ababababc";
    char string2[] = "9abaabaaba";
    int pos = indexKMP(string1, string2, 1);
    cout << "KMP算法匹下标:" << pos << endl;
}


