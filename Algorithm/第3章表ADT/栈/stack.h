//
// Created by andy on 16/6/18.
//

#ifndef ALGORITHM_STACK_H
#define ALGORITHM_STACK_H

#define EMPTYSTACK INT_MIN

typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

// 创建一个空栈
Stack CreateStack(void);

// 判断堆栈是否为空
int IsEmpty(Stack stack);

// 释放堆栈空间
void DisposeStack(Stack stack);

// 使得全栈为空
void MakeEmpty(Stack stack);

// 压入一个元素到堆栈中
void Push(ElementType X, Stack stack);

// 弹出栈顶元素(有返回值,可以被接收)
ElementType Top(Stack stack);

// 弹出栈顶元素
void Pop(Stack stack);

// 遍历整个堆栈
void TraversalStack(Stack stack);

// 堆栈的基本数据结构
struct Node
{
    ElementType Element;
    PtrToNode Next;
};

// 创建一个空的堆栈(注意带有头节点)
Stack CreateStack(void)
{
    PtrToNode node = (PtrToNode) malloc(sizeof(struct Node));
    if (node == NULL)
        cout << "Out of space!!!";
    node->Element = EMPTYSTACK;
    node->Next = NULL;
    return node;
}

// 判断堆栈是否为空
int IsEmpty(Stack stack)
{
    return stack->Next == NULL;
}

// 释放堆栈空间(保留头结点)
void DisposeStack(Stack stack)
{
    PtrToNode node = stack->Next,temp;
    stack->Next = NULL;         // 注意将头结点的指针置空
    while(node!=NULL)
    {
        temp = node->Next;
        free(node);             // 注意释放了node结点后,不能再用node->next
        node = temp;
    }
}

// 压栈
void Push(ElementType X, Stack stack)
{
    PtrToNode temp;
    if (stack == NULL)
        return;
    temp = (PtrToNode) malloc(sizeof(struct Node));
    temp->Element = X;
    temp->Next = stack->Next;           // 链表头默认为 堆栈顶端(元素插入在堆栈头部)
    stack->Next = temp;
}

// 弹栈
void Pop(Stack stack)
{
    Top(stack);
}

// 弹栈
ElementType Top(Stack stack)
{
    PtrToNode temp;
    ElementType element;
    if (IsEmpty(stack))
    {
        cout << "Pop failed. Stack is empty!";
        return EMPTYSTACK;
    }
    temp = stack->Next;
    element = temp->Element;
    stack->Next = temp->Next;
    free(temp);     // 释放结点
    temp = NULL;
    return element;
}


// 遍历整个堆栈
void TraversalStack(Stack stack)
{
    PtrToNode temp = stack->Next;
    if (temp == NULL)
    {
        cout << "Stack is empty!!!" << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << temp->Element << " ";
        temp = temp->Next;
    }
    cout << "" << endl;
}

#endif //ALGORITHM_STACK_H
