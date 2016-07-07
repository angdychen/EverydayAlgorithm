// 1. 插入类排序
//      2. 希尔排序
//          时间复杂度: O(N^2)
//          空间复杂度: O(1)
//          稳定性:  不稳定
// Created by andy on 16/7/7.
//

#include <iostream>

using namespace std;

typedef int ElementType;

void ShellSort(ElementType A[], int N)
{
    int i, j, Increment;
    ElementType Tmp;
    for (Increment = N / 2; Increment > 0; Increment /= 2) // 增量
    {
        for (i = Increment; i < N; i++)                             // 直接排序
        {
            Tmp = A[i];
            for (j = i; j >= Increment; j -= Increment)
            {
                if (Tmp < A[j - Increment])
                    A[j] = A[j - Increment];
                else
                    break;
            }
            A[j] = Tmp;
        }
    }
}

int main()
{

    int array[10];
    int i = 0;
    for (; i < 10; i++) array[i] = 10 - i;

    cout << "1.希尔排序" << endl;
    cout << "\t原序列为: ";
    for (i = 0; i < 10; i++) cout << array[i] << " ";

    cout << endl << "\t排序后为: ";
    ShellSort(array, 10);
    for (i = 0; i < 10; i++) cout << array[i] << " ";

    return 0;
}