//
// Created by andy on 16/10/30.
//

#include <iostream>

using namespace std;

#include "BinHeap.h"

bool isMatch(char *s, char *p)
{
    // 递归版,时间复杂度O(n),空间复杂度O(1)
    if (*p == '\0') return *s == '\0';

    // next char is not '*', then must match current character
    if (*(p + 1) != '*')
    {
        if ((*p == *s) || (*p == '.' && *s != '\0'))
            return isMatch(s + 1, p + 1);
        else
            return false;
    }
        // next char is '*'
    else
    {
        while (*p == *s || (*p == '.' && *s != '\0'))
        {
            if (isMatch(s, p + 2))
                return true;
            s++;
        }
        return isMatch(s, p + 2);
    }

}

bool isMatch2(char *s, char *p)
{
    // 递归版,时间复杂度O(n),空间复杂度O(1)
    if (*p == '\0') return *s == '\0';

    // next char is not '*', then must match current character
    if (*(p + 1) != '*')
    {
        if (*p == *s || (*p == '.' && *s != '\0'))
            return isMatch(s + 1, p + 1);
        else
            return false;
    }
        // next char is '*'
    else
    {
        // try the length of 0
        if (isMatch(s, p + 2))
            return true;
        // try all possible lengths
        while (*p == *s || (*p == '.' && *s != '\0'))
        {
            if (isMatch(++s, p + 2)) return true;
        }
        return false;

    }
}

int main()
{
    PriorityQueue H = Initialize(10);
    for (int i = 10; i > 0; i--)
    {
        Insert(i, H);
    }
    for (int i = 1; i <= H->size; i++)
    {
        cout << H->Elements[i] << " ";
    }

    cout << endl;
    DeleteMin(H);
    for (int i = 1; i <= H->size; i++)
    {
        cout << H->Elements[i] << " ";
    }

    cout << endl;
    DeleteMin(H);
    for (int i = 1; i <= H->size; i++)
    {
        cout << H->Elements[i] << " ";
    }
    return 0;
}

