//
// Created by andy on 16/6/17.
//

#ifndef ALGORITHM_POLYNOMIAL_H
#define ALGORITHM_POLYNOMIAL_H

typedef struct Node *PtrToNode;

// 多项式(每一项的定义)
struct Node
{
    int Coefficient;    // 系数
    int Exponent;       // 指数
    PtrToNode Next;
};

typedef PtrToNode Polynomial;   // 排序好的结点

// 初始化一个多项式
PtrToNode MakeEmpty()
{
    PtrToNode node;
    node = (PtrToNode) malloc(sizeof(struct Node));
    if (node == NULL)
        cout << "Out of space" << endl;
    node->Coefficient = -1;
    node->Exponent = -1;
    node->Next = NULL;
    return node;
}

// 插入多项式结点
void InsertNode(PtrToNode X, Polynomial P)
{
    PtrToNode cur = P;
    while (cur->Next != NULL && cur->Next->Exponent > X->Exponent)
    {
        cur = cur->Next;
    }
    if (cur->Next != NULL && cur->Next->Exponent == X->Exponent)
    {
        cout << "指数相同,禁止插入!" << endl;
        return;
    }
    X->Next = cur->Next;
    cur->Next = X;
}

// 删除整个表达式(释放结点)
void DeletePloynomial(Polynomial ploy)
{
    PtrToNode ptr = ploy->Next , temp;
    ploy->Next = NULL;
    while(ptr!=NULL)
    {
        temp = ptr->Next;
        free(ptr);
        ptr = temp;
    }
}

// 遍历整个多项式
void TraversalPolynomial(Polynomial P)
{
    int count = 0;      // 统计多项式结点个数
    for (PtrToNode TmpCell = P->Next; TmpCell != NULL; TmpCell = TmpCell->Next)
    {
        cout << TmpCell->Coefficient << "^" << TmpCell->Exponent << "  ";
        ++count;
    }
    cout << "" << endl;
    cout << "多项式中结点个数为: " << count << endl;
}

// 多项式的加法
// const Polynomial poly1 和 Polynomial const poly1的区别
Polynomial AddPolynomial(const Polynomial poly1, const Polynomial poly2)
{
    Polynomial polynomial = MakeEmpty();
    PtrToNode ptr1 = poly1->Next;   // 取第一个结点
    PtrToNode ptr2 = poly2->Next;   // 取第一个结点
    // 两个指针同时移动(相互制约)
    while (ptr1 != NULL && ptr2 != NULL)
    {
        PtrToNode temp = (PtrToNode) malloc(sizeof(struct Node));
        if (ptr1->Exponent > ptr2->Exponent)
        {
            temp->Exponent = ptr1->Exponent;
            temp->Coefficient = ptr1->Coefficient;
            ptr1 = ptr1->Next;
        } else if (ptr1->Exponent < ptr2->Exponent)
        {
            temp->Exponent = ptr2->Exponent;
            temp->Coefficient = ptr2->Coefficient;
            ptr2 = ptr2->Next;
        } else
        {
            temp->Exponent = ptr1->Exponent;
            temp->Coefficient = ptr1->Coefficient + ptr2->Coefficient;
            ptr1 = ptr1->Next;
            ptr2 = ptr2->Next;
        }
        temp->Next = NULL;
        if (temp->Coefficient != 0)            // 如果系数已为0,则无需再插入到多项式中
        {
            InsertNode(temp, polynomial);
        } else
        {
            free(temp);                 // free(temp)的结果是:temp正在指向的地址没有变,但是该地址处的数据此时已经无定义了
        }
    }
    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            PtrToNode temp = (PtrToNode) malloc(sizeof(struct Node));
            temp->Exponent = ptr2->Exponent;
            temp->Coefficient = ptr2->Coefficient;
            temp->Next = NULL;
            ptr2 = ptr2->Next;
            if (temp->Coefficient != 0)             // 如果系数已为0,则无需再插入到多项式中
            {
                InsertNode(temp, polynomial);
            } else
            {
                free(temp);                        // free(P)的结果是:P正在指向的地址没有变,但是该地址处的数据此时已经无定义了
            }
        }
    }
    if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            PtrToNode temp = (PtrToNode) malloc(sizeof(struct Node));
            temp->Exponent = ptr1->Exponent;
            temp->Coefficient = ptr1->Coefficient;
            temp->Next = NULL;
            ptr1 = ptr1->Next;
            if (temp->Coefficient != 0)             // 如果系数已为0,则无需再插入到多项式中
            {
                InsertNode(temp, polynomial);
            } else
            {
                free(temp);                        // free(P)的结果是:P正在指向的地址没有变,但是该地址处的数据此时已经无定义了
            }
        }
    }
    return polynomial;
}

// 多项式的减法
Polynomial SubPolynomial(const Polynomial poly1, const Polynomial poly2)
{
    Polynomial polynomial = MakeEmpty();
    PtrToNode ptr1 = poly1->Next;   // 取第一个结点
    PtrToNode ptr2 = poly2->Next;   // 取第一个结点
    // 两个指针同时移动(相互制约)
    while (ptr1 != NULL && ptr2 != NULL)
    {
        PtrToNode temp = (PtrToNode) malloc(sizeof(struct Node));
        if (ptr1->Exponent > ptr2->Exponent)
        {
            temp->Exponent = ptr1->Exponent;
            temp->Coefficient = ptr1->Coefficient;
            ptr1 = ptr1->Next;
        } else if (ptr1->Exponent < ptr2->Exponent)
        {
            temp->Exponent = ptr2->Exponent;
            temp->Coefficient = -ptr2->Coefficient;
            ptr2 = ptr2->Next;
        } else
        {
            temp->Exponent = ptr1->Exponent;
            temp->Coefficient = ptr1->Coefficient - ptr2->Coefficient;
            ptr1 = ptr1->Next;
            ptr2 = ptr2->Next;
        }
        temp->Next = NULL;
        if (temp->Coefficient != 0)             // 如果系数已为0,则无需再插入到多项式中
        {
            InsertNode(temp, polynomial);
        } else
        {
            free(temp);                        // free(P)的结果是:P正在指向的地址没有变,但是该地址处的数据此时已经无定义了
        }
    }
    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            PtrToNode temp = (PtrToNode) malloc(sizeof(struct Node));
            temp->Exponent = ptr2->Exponent;
            temp->Coefficient = -ptr2->Coefficient;
            temp->Next = NULL;
            ptr2 = ptr2->Next;
            if (temp->Coefficient != 0)             // 如果系数已为0,则无需再插入到多项式中
            {
                InsertNode(temp, polynomial);
            } else
            {
                free(temp);                        // free(P)的结果是:P正在指向的地址没有变,但是该地址处的数据此时已经无定义了
            }
        }
    }

    if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            PtrToNode temp = (PtrToNode) malloc(sizeof(struct Node));
            temp->Exponent = ptr1->Exponent;
            temp->Coefficient = ptr1->Coefficient;
            temp->Next = NULL;
            ptr1 = ptr1->Next;
            if (temp->Coefficient != 0)             // 如果系数已为0,则无需再插入到多项式中
            {
                InsertNode(temp, polynomial);
            } else
            {
                free(temp);                        // free(P)的结果是:P正在指向的地址没有变,但是该地址处的数据此时已经无定义了
            }
        }
    }
    return polynomial;
}

// 多项式的相乘
Polynomial MultPolynomial(const Polynomial poly1, const Polynomial poly2)
{
    Polynomial result = MakeEmpty();
    Polynomial polynomial = MakeEmpty();
    PtrToNode ptr1 = poly1->Next;
    PtrToNode ptr2 = poly2->Next;
    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            PtrToNode temp = (PtrToNode) malloc(sizeof(struct Node));
            temp->Exponent = ptr1->Exponent + ptr2->Exponent;               // 指数相加
            temp->Coefficient = ptr1->Coefficient * ptr2->Coefficient;      // 系数相乘
            temp->Next = NULL;
            if (temp->Coefficient != 0)             // 如果系数已为0,则无需再插入到多项式中
            {
                InsertNode(temp, polynomial);
            } else
            {
                free(temp);                        // free(P)的结果是:P正在指向的地址没有变,但是该地址处的数据此时已经无定义了
            }
            ptr2 = ptr2->Next;
        }
        result = AddPolynomial(result, polynomial);
        DeletePloynomial(polynomial);                                    // 释放所有多项式中的结点
        polynomial = MakeEmpty();
        ptr1 = ptr1->Next;
        ptr2 = poly2->Next;
    }
    return result;
}

#endif //ALGORITHM_POLYNOMIAL_H
