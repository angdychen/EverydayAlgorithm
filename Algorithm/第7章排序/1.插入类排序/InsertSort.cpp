// 1. 插入类排序
//      1. 直接插入排序
//          时间复杂度: O(N^2)
//          空间复杂度: O(1)
//          稳定性:  稳定
// Created by andy on 16/7/6.
//
#include <iostream>

using namespace std;

typedef int ElementType;

// 1. 直接插入排序(注意下标)
void InsertionSort(ElementType A[], int N)
{
    int i, j, temp;
    for (i = 1; i < N; i++)
    {
        temp = A[i];
        for (j = i - 1; j >= 0 && temp < A[j]; j--)
            A[j + 1] = A[j];
        A[j + 1] = temp;
    }
}

int main()
{
    int array[10];
    int i = 0;
    for (; i < 10; i++) array[i] = 10 - i;

    cout << "1.直接插入排序" << endl;
    cout << "\t原序列为: ";
    for (i = 0; i < 10; i++) cout << array[i] << " ";

    cout << endl << "\t排序后为: ";
    InsertionSort(array, 10);
    for (i = 0; i < 10; i++) cout << array[i] << " ";

    return 0;
}
