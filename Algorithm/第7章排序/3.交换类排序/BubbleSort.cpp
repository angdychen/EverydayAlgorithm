// 3. 交换类排序
//      1. 冒泡排序
//          时间复杂度: O(N^2)
//          空间复杂度: O(1)
//          稳定性:  稳定
// Created by andy on 16/7/7.
//

#include <iostream>

using namespace std;

typedef int ElementType;

void Swap(ElementType *a, ElementType *b)
{
    ElementType temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(ElementType A[], int N)
{
    int i, j;
    for (i = N - 1; i >= 0; i--)
    {
        for(j=0;j<i;j++)
        {
            if (A[j] > A[j + 1])
                Swap(&A[j], &A[j + 1]);
        }
    }
}

int main()
{
    int array[10];
    int i = 0;
    for (; i < 10; i++) array[i] = 10 - i;

    cout << "3.交换类排序(冒泡排序)" << endl;
    cout << "\t原序列为: ";
    for (i = 0; i < 10; i++) cout << array[i] << " ";

    cout << endl << "\t排序后为: ";
    BubbleSort(array, 10);
    for (i = 0; i < 10; i++) cout << array[i] << " ";
    return 0;
}
