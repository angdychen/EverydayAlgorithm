// 2. 选择类排序
//      2. 堆排序
//          时间复杂度: O(NlogN)
//          空间复杂度: O(1)
//          稳定性:  不稳定
// Created by andy on 16/7/7.
//

#include <iostream>

using namespace std;

// 注意这里的堆从0开始
#define LeftChild(i) ( 2*(i) + 1)

typedef int ElementType;

void PercDown(ElementType A[], int i, int N)
{
    int Child;
    ElementType Tmp;
    for (Tmp = A[i]; LeftChild(i) < N; i = Child)
    {
        Child = LeftChild(i);
        if (Child != N - 1 && A[Child + 1] > A[Child])
            Child++;
        if (Tmp < A[Child]) A[i] = A[Child];
        else break;
    }
    A[i] = Tmp;
}

void Swap(ElementType *a, ElementType *b)
{
    ElementType temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void HeapSort(ElementType A[], int N)
{
    int i;
    for (i = N / 2; i >= 0; i--)    /*BuildHeap*/
        PercDown(A, i, N);
    for (i = N - 1; i > 0; i--)
    {
        Swap(&A[0], &A[i]);         /*DeleteMax*/
        PercDown(A, 0, i);
    }
}

int main()
{
    int array[10];
    int i = 0;
    for (; i < 10; i++) array[i] = 10 - i;

    cout << "2.堆排序" << endl;
    cout << "\t原序列为: ";
    for (i = 0; i < 10; i++) cout << array[i] << " ";

    cout << endl << "\t排序后为: ";
    HeapSort(array, 10);
    for (i = 0; i < 10; i++) cout << array[i] << " ";
    return 0;
}

