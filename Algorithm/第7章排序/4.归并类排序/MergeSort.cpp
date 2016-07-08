// 4. 归并类排序
//         归并排序
//          时间复杂度: O(NlogN)
//          空间复杂度: O(N)
//          稳定性:  不稳定
// Created by andy on 16/7/8.
//

#include <iostream>

using namespace std;

#define N 10

typedef int ElementType;

ElementType *Tmp = (ElementType *) malloc(N * sizeof(ElementType));

// 合并
void Merge(ElementType A[], int left, int mid, int right)
{
    int i, j, k;
    for (i = left; i <= right; i++)
    {
        Tmp[i] = A[i];  // 拷贝一份副本
    }
    // 注意这里哪个下标在动
    for (j = left, k = mid + 1, i = left; j <= mid && k <= right; i++)
    {
        if (Tmp[j] < Tmp[k]) A[i] = Tmp[j++];
        else A[i] = Tmp[k++];
    }
    while (j <= mid) A[i++] = Tmp[j++];        //  这里的思想非常重要(leetcode中数组部分前5题)
    while (k <= right) A[i++] = Tmp[k++];
}

// 分治的思想
void MergeSort(ElementType A[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid + 1, right);
        Merge(A, left, mid, right);
    }
}

int main()
{
    int array[10];
    int i = 0;
    for (; i < 10; i++) array[i] = 10 - i;

    cout << "3.交换类排序(归并排序)" << endl;
    cout << "\t原序列为: ";
    for (i = 0; i < 10; i++) cout << array[i] << " ";

    cout << endl << "\t排序后为: ";
    MergeSort(array, 0, 9);
    for (i = 0; i < 10; i++) cout << array[i] << " ";
    return 0;
}