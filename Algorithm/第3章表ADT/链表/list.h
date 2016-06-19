//
// Created by andy on 16/6/6.
//

#ifndef ALGORITHM_LIST_H
#define ALGORITHM_LIST_H

typedef int Element;

// 节点定义
typedef struct node {
    Element data;
    struct node * next;
}Node;

// 定义节点类型指针
typedef struct node * PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

// 链表ADT
List MakeEmpty();
int IsEmpty(List L);
int IsLast(Position p, List L);

Position Find(Element x, List L);
Position FindPrevious(Element x, List L);

void Insert(Element x, List L);
void Insert(Element x, List L, Position P);

void Delete(Element x, List L);
void DeleteList(List L);

void TraversalList(List L);

Position Header(List L);
Position First(List L);
Position Advance(Position P);
Element Retrieve(Position P);

List Reverse(List L);

// 即CreatEmptyList,创建一个空链表
List MakeEmpty()
{
    Position P;
    P = (Position)malloc(sizeof(struct node));
    if(P == NULL)
        cout << "Out of space" << endl;
    P->data = 0;    // Header头指针数据域可利用(此处未利用)
    P->next = NULL;
    return P;

}

// 判断当前链表是否为空
int IsEmpty(List L)
{
    return L->next == NULL;
}

// 判断是否为最后一个节点
int IsLast(Position P, List L)
{
    return P->next == NULL;
}

// 查找数据域为x的节点,如果查找失败则返回空节点
Position Find(Element x, List L)
{
    Position P;
    P = L->next;
    while (P != NULL && P->data != x)
    {
        P = P->next;
    }
    return P;
}

// 找到x的前一个元素,如不存在则返回表尾指针
Position FindPrevious(Element x, List L)
{
    Position P;

    P = L;
    while(P->next != NULL && P->next->data != x)
        P = P->next;
    return P;   // 若不存在则返回表尾指针
}

// 返回链表中最后一个节点
Position FindLast(List L)
{
    Position P = L;
    while(P->next != NULL) P = P->next;
    return P;
}

// 删除数据域为X的节点
void Delete(Element x, List L)
{
    Position P, TmpCell;
    P = FindPrevious(x, L);
    if(!IsLast(P, L))
    {
        TmpCell = P->next;
        P->next = TmpCell->next;
        free(TmpCell);
        // free的作用是告诉操作系统,TmpCell所指向的这块内存区域可以收回
    }
}

// 在链表最后插入
void Insert(Element x, List L)
{
    Position P = L, TmpCell;
    while(L->next!=NULL) L = L->next;
    TmpCell = (Position)malloc(sizeof(struct node));
    TmpCell->data = x;
    TmpCell->next = NULL;
    L->next = TmpCell;
}

// 在节点P后面插入元素
void Insert(Element x, List L, Position P)
{
    Position TmpCell;
    TmpCell = (Position)malloc(sizeof(struct node));
    if(TmpCell == NULL)
        cout << "Out of space" << endl;

    TmpCell->data = x;
    TmpCell->next = P->next;
    P->next = TmpCell;
}

// 删除整个链表
void DeleteList(List L)
{
    Position P, Tmp;
    P = L->next;
    L->next = NULL;
    while(P->next != NULL)
    {
        Tmp = P->next;
        free(P);
        P = Tmp;
    }
}

// 遍历链表
void TraversalList(List L)
{
    int count = 0;
    for(Position TmpCell = L->next; TmpCell != NULL;  TmpCell = TmpCell->next) {
        cout << TmpCell->data << " ";
        ++count;
    }
    cout << "" << endl;
    cout << "当前list中元素总个数为: " << count << endl;
}

// 单链表反转
List Reverse(List L)
{
    Position Header, PreCell, CurCell, NextCell;
    Header = L;             // 得到头节点
    PreCell = L->next;      // 第一个节点
    CurCell = PreCell->next;                // 第二个节点
    if(PreCell == NULL || CurCell == NULL)  // 如果0个或1个节点
        return Header;

    PreCell->next = NULL;   // 特别注意第一个节点要回空(否则将进入死循环)
    while(CurCell!=NULL)
    {
        NextCell = CurCell->next;
        CurCell->next = PreCell;
        PreCell = CurCell;
        CurCell = NextCell;
    }
    Header->next = PreCell;
    return Header;
}

#endif //ALGORITHM_LIST_H
