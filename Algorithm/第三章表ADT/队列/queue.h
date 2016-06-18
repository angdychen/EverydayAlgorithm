//
// Created by andy on 16/6/18.
// 基本数据结构之三: 队列 Queue
//

#ifndef ALGORITHM_QUEUE_H
#define ALGORITHM_QUEUE_H

#include <iostream>

using namespace std;

#define HEADELEMENT INT_MIN

typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;     // 结点
typedef PtrToNode Queue;            // 队列

// 创建一个队列(包含头指针)
Queue CreateQueue();

// 队列是否为空
int IsEmpty(Queue queue);

// 进队(先进先出,元素应该插在链表的最末尾)
void Enqueue(ElementType X, Queue queue);

// 出队(先进先出,应该从链表的第一个有效结点开始弹出)
void Dequeue(Queue queue);

// 出队(元素出列,可被接收)
ElementType Front(Queue queue);

// 释放队列空间
void DisposeQueue(Queue queue);

// 遍历整个队列
void TraversalQueue(Queue queue);

// 队列的基本数据结构
struct Node
{
    ElementType Element;
    PtrToNode Next;
};

// 创建一个队列(包含头指针)
Queue CreateQueue()
{
    Queue queue = (PtrToNode) malloc(sizeof(struct Node));
    if (queue == NULL)
    {
        cout << "Out of space!!!" << endl;
    }
    queue->Element = HEADELEMENT;
    queue->Next = NULL;
    return queue;
}

// 队列是否为空
int IsEmpty(Queue queue)
{
    return queue->Next == NULL;
}

// 进队(先进先出,元素应该插在链表的最末尾) 堆栈是插在最前端
void Enqueue(ElementType X, Queue queue)
{
    PtrToNode ptr, temp;
    ptr = queue;
    while (ptr->Next != NULL) ptr = ptr->Next;       // 移动到最后一个结点

    temp = (PtrToNode) malloc(sizeof(struct Node));
    temp->Element = X;
    temp->Next = NULL;
    ptr->Next = temp;
}

// 出队(先进先出,应该从链表的第一个有效结点开始弹出)
void Dequeue(Queue queue)
{
    Front(queue);
}

// 出队(元素出列,可被接收)
ElementType Front(Queue queue)
{
    PtrToNode temp;
    ElementType element;
    if (IsEmpty(queue))
    {
        cout << "Front failed. Queue is empty!!!";
        return HEADELEMENT;
    }
    temp = queue->Next;
    element = temp->Element;
    queue->Next = temp->Next;
    free(temp);         // 释放结点
    temp = NULL;
    return element;
}

// 释放队列空间
void DisposeQueue(Queue queue)
{
    PtrToNode node = queue->Next, temp;
    if (IsEmpty(queue)) return;
    queue->Next = NULL;                 // 注意将头结点的指针置空
    while (node != NULL)
    {
        temp = node->Next;
        free(node);                     // 注意释放了node结点后,不能再用node->next
        node = temp;
    }
}

// 遍历整个队列
void TraversalQueue(Queue queue)
{
    PtrToNode node = queue->Next;
    if (node == NULL)
    {
        cout << "Queue is empty!!!";
        return;
    }
    while (node != NULL)
    {
        cout << node->Element << " ";
        node = node->Next;
    }
    cout << "" << endl;
}

#endif //ALGORITHM_QUEUE_H
