// 3. 交换类排序
//      2. 快速排序(分而治之的思想,很重要divide and conquer)
//          时间复杂度: 最坏O(n^2) 平均O(NlogN)
//          空间复杂度: O(logn)
//          稳定性:  不稳定
// Created by andy on 16/7/7.
//

#include <iostream>

using namespace std;

typedef int ElementType;

// 一趟排序,返排序后枢纽元素的位置
int Partition(ElementType A[], int left, int right)
{
    ElementType pivot = A[left];     // 枢纽元素(枢纽元素的选择,有多种,此处选定第一个元素为枢纽元素)
    if (left < right)
    {
        while (left < right && A[right] >= pivot) --right;
        A[left] = A[right];
        while (left < right && A[left] <= pivot) ++left;
        A[right] = A[left];
    }
    A[left] = pivot;
    return left;
}

// 快速排序
void QuickSort(ElementType A[], int left, int right)
{
    int pivotPos;      // 枢纽节点位置
    if (left < right)
    {
        pivotPos = Partition(A, left, right);
        QuickSort(A, left, pivotPos);
        QuickSort(A, pivotPos + 1, right);
    }
}

int main()
{
    int array[10];
    int i = 0;
    for (; i < 10; i++) array[i] = 10 - i;

    cout << "3.交换类排序(快速排序排序)" << endl;
    cout << "\t原序列为: ";
    for (i = 0; i < 10; i++) cout << array[i] << " ";

    cout << endl << "\t排序后为: ";
    QuickSort(array, 0, 9);
    for (i = 0; i < 10; i++) cout << array[i] << " ";
    return 0;
}