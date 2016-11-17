//
// Created by andy on 16/10/30.
// 优先队列的申明
//

#ifndef ALGORITHM_BINHEAP_H
#define ALGORITHM_BINHEAP_H

/* 初始化队列,最小容量值*/
#define MinPriorityQueueSize 0

#include <iostream>

using namespace std;

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
typedef int ElementType;

PriorityQueue Initialize(int MaxElements);

void Destroy(PriorityQueue H);

void MakeEmpty(PriorityQueue H);

void Insert(ElementType X, PriorityQueue H);

ElementType DeleteMin(PriorityQueue H);

ElementType FindMin(PriorityQueue H);

int IsEmpty(PriorityQueue H);

int IsFull(PriorityQueue H);

struct HeapStruct
{
    int Capacity;
    int size;
    ElementType *Elements;
};

// 初始化优先队列
PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;
    if (MaxElements < MinPriorityQueueSize)
        cout << "Priority queue size is too small" << endl;
    H = (PriorityQueue) malloc(sizeof(struct HeapStruct));
    if (H == NULL)
        cout << "Out of space!!!" << endl;
    /* 多分配一个哨兵元素的空间 */
    H->Elements = (ElementType *) malloc((MaxElements + 1) * sizeof(ElementType));
    if (H->Elements == NULL)
        cout << "Out of space!!!" << endl;
    H->Capacity = MaxElements;
    H->size = 0;
    /* 哨兵元素 */
    H->Elements[0] = INT_MIN;

    return H;
}

// 在最小堆中插入元素(即建堆过程,时间复杂度为:o(logn))
void Insert(ElementType X, PriorityQueue H)
{
    int i;
    for (i = ++H->size; H->Elements[i / 2] > X; i /= 2)
        H->Elements[i] = H->Elements[i / 2];
    H->Elements[i] = X;
}

// 删除最小堆的跟节点(即最小元素,时间复杂度为:o(logn))
// 堆中存在偶数个元素的时候,此时将遇到一个节点只有一个儿子的情况。
ElementType DeleteMin(PriorityQueue H)
{
    int i, Child;
    ElementType MinElement, LastElement;

    MinElement = H->Elements[1];
    LastElement = H->Elements[H->size--];

    for (i = 1; i * 2 <= H->size; i = Child)
    {
        /* Find smaller child */
        Child = i * 2;
        /* If Child==H->size, it indicates this node has not right-child*/
        if (Child != H->size && H->Elements[Child + 1] < H->Elements[Child])
            Child++;
        if (LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = LastElement;
    return MinElement;
}

// 清空优先队列
void MakeEmpty(PriorityQueue H)
{
    H->size = 0;
}

// 判断是否为空队列
int IsEmpty(PriorityQueue H)
{
    return H->size == 0;
}

// 判读优先队列是否满
int IsFull(PriorityQueue H)
{
    return H->size == H->Capacity;
}

// 销毁优先队列
void Destroy(PriorityQueue H)
{
    free(H->Elements);
    free(H);
}

#endif //ALGORITHM_BINHEAP_H
