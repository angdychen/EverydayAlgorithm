//
// 一颗AVL树是其每个节点的左子树和右子树的高度最多相差1的二叉查找树
// Created by andy on 16/7/15.
//

#include <iostream>

using namespace std;

struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;
typedef struct AVLNode *Tree;

typedef char ElementType;

struct AVLNode
{
    ElementType Element;
    AVLTree Left;
    AVLTree Right;
    int Height;
};

AVLTree MakeEmpty(AVLTree T);

Position Find(ElementType X, AVLTree T);

Position FindMin(AVLTree T);

Position FindMax(AVLTree T);

AVLTree Insert(ElementType X, AVLTree T);

AVLTree Delete(ElementType X, AVLTree T);

AVLTree FindMin(AVLTree T);

AVLTree FindMax(AVLTree T);

ElementType Retrieve(Position);

int Height(Position P);

int Max(int a, int b);

// 左节点(最左边的节点就是最小的元素)
Position FindMin(Tree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T;
    else return FindMin(T->Left);
}

// 右节点(最右边的节点就是最大的元素)
Position FindMax(Tree T)
{
    if (T == NULL) return NULL;
    else if (T->Right == NULL) return T;
    else return FindMax(T->Right);
}

// 单旋转(左旋转) 第一种情形
Position SingleRotateWithLeft(Position K2)
{
    Position K1;
    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
    return K1;
}

// 单旋转(右旋转) 第四种情形
Position SingleRotateWithRight(Position K1)
{
    Position K2;
    K2 = K1->Right;
    K1->Right = K2->Left;
    K2->Left = K1;

    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    return K2;
}

// 双旋转(左-右旋转)
Position DoubleRotateWithRight(Position K1)
{
    K1->Right = SingleRotateWithLeft(K1->Right);
    return SingleRotateWithRight(K1);
}


// 双旋转(右-左旋转)
Position DoubleRotateWithLeft(Position K3)
{
    K3->Left = SingleRotateWithRight(K3->Left);
    return SingleRotateWithLeft(K3);
}


AVLTree Insert(ElementType X, AVLTree T)
{
    if (T == NULL)
    {
        T = (AVLTree) malloc(sizeof(struct AVLNode));
        if (T == NULL)
        {
            cout << "Out of space!!!" << endl;
        }
        else
        {
            T->Element = X;
            T->Left = NULL;
            T->Right = NULL;
        }
    } else if (X < T->Element)
    {
        T->Left = Insert(X, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2)
        {
            if (X < T->Left->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    } else if (X > T->Element)
    {
        T->Right = Insert(X, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2)
        {
            if (X > T->Right->Element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }
    // 如果相等就不插入
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

AVLTree Delete(ElementType X, AVLTree T)
{
    Position TmpCell = NULL;
    if (T == NULL)          // 空树直接返回
        return NULL;

    // 如果待删除元素小于当前节点,则 往左
    if (X < T->Element)
    {
        T->Left = Delete(X, T->Left);
        if (Height(T->Right) - Height(T->Left) == 2)
        {
            if (Height(T->Right->Left) > Height(T->Right->Right))
                T = DoubleRotateWithRight(T);
            else
                T = SingleRotateWithRight(T);

        }
    }
        // 如果待删除元素大于当前节点,则 往右
    else if (X > T->Element)
    {
        T->Right = Delete(X, T->Right);
        if (Height(T->Left) - Height(T->Right) == 2)
        {
            if (Height(T->Left->Right) > Height(T->Left->Left))
                T = DoubleRotateWithLeft(T);
            else
                T = SingleRotateWithLeft(T);
        }
    }
        // 如果找到最小值了(1. 所找到的节点有两个孩子)
    else
    {
        if (T->Right != NULL)
        {   // 右子树不为空的情况
            Position TmpCell = T->Right;
            TmpCell = FindMin(TmpCell);
            T->Element = TmpCell->Element;
            T->Height = TmpCell->Height;
            T->Right = Delete(T->Height, T->Right);//删除后继节点
        } else
        {   //右子树为空的情况，free节点，返回被删除节点的左节点
            //这也是真正删除节点的地方
            Position TmpCell = T;
            T = T->Left;
            free(TmpCell);
            return T;
        }
    }
    // ************ 以上部分和删除二叉查找树过程完全一样 **************  //
    //每次删除之后，都要更新ßΩ节点的高度
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;

}

int Height(Position P)
{
    if (P == NULL)
    { return -1; }
    else
        return P->Height;
}

int Max(int a, int b)
{
    return a > b ? a : b;
}


void PreOrderTraverse(Tree T)
{
    if (T != NULL)
    {
        cout << T->Element << " ";
        PreOrderTraverse(T->Left);
        PreOrderTraverse(T->Right);
    }
}

void InOrderTraverse(Tree T)
{
    if (T != NULL)
    {
        InOrderTraverse(T->Left);
        cout << T->Element << " ";
        InOrderTraverse(T->Right);
    }
}

int main()
{
    int arr[10] = {9, 3, 5, 7, 1, 0, 2, 4, 8, 6};;
    AVLTree S = NULL;

    // 随机插入一批元素(重复元素不插入)
    for (int i = 0; i < 10; i++)
    {
        char a = arr[i] + '0';
        S = Insert(a, S);
    }
    PreOrderTraverse(S);
    cout << endl;
    InOrderTraverse(S);

    cout << endl;
    S = Delete('9', S);
    PreOrderTraverse(S);
    cout << endl;
    InOrderTraverse(S);
    cout << endl;

    S = Delete('0', S);
    PreOrderTraverse(S);
    cout << endl;
    InOrderTraverse(S);

}

