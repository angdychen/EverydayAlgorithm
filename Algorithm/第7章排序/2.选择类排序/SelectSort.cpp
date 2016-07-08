// 2. 选择类排序
//      1. 简单排序
//          时间复杂度: O(N^2)
//          空间复杂度: O(1)
//          稳定性:  不稳定
// Created by andy on 16/7/7.
//

#include <iostream>

using namespace std;

typedef int ElementType;

void SelectSort(ElementType A[], int N)
{
    int i, j, min;
    ElementType temp;
    for (i = 0; i < N; i++)
    {
        temp = A[i];     // 交换中间量
        min = i;         // 记录最小下标位置
        for (j = i + 1; j < N; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}

int main()
{
    int array[10];
    int i = 0;
    for (; i < 10; i++) array[i] = 10 - i;

    cout << "2.简单选择排序" << endl;
    cout << "\t原序列为: ";
    for (i = 0; i < 10; i++) cout << array[i] << " ";

    cout << endl << "\t排序后为: ";
    SelectSort(array, 10);
    for (i = 0; i < 10; i++) cout << array[i] << " ";
    return 0;
}