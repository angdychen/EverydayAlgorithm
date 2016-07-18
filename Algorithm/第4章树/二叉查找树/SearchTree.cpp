//
// Created by andy on 16/7/10.
//

#include <iostream>

using namespace std;

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef struct TreeNode *Tree;

typedef char ElementType;

/****************** 数据结构 ********************/

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

/****************** 函数定义 ********************/

// 清空一颗二叉树
SearchTree MakeEmpty(SearchTree T);
// 查找指定元素
Position Find(ElementType X, SearchTree T);
// 查找树中最小的元素,并返回其结点
Position FindMin(SearchTree T);
// 查找树中最大的元素,并返回其结点
Position FindMax(SearchTree T);
// 向当前二叉查找树中,插入指定元素
SearchTree Insert(ElementType X, SearchTree T);
// 删除指定元素
SearchTree Delete(ElementType X, SearchTree T);
// 查找指定位置上的元素
ElementType Retrieve(Position P);

/****************** 函数实现 ********************/

SearchTree MakeEmpty(SearchTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return T;
}

Position Find(ElementType X, SearchTree T)
{
    if (T == NULL) return NULL;
    if (X < T->Element) return Find(X, T->Left);
    else if (X > T->Element) return Find(X, T->Right);
    else return T;
}

// 左节点(最左边的节点就是最小的元素)
Position FindMin(SearchTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T;
    else return FindMin(T->Left);
}

// 右节点(最右边的节点就是最大的元素)
Position FindMax(SearchTree T)
{
    if (T == NULL) return NULL;
    else if (T->Right == NULL) return T;
    else return FindMax(T->Right);
}

// 注意区别二叉查找树 和 二叉平衡树()
SearchTree Insert(ElementType X, SearchTree T)
{
    if (T == NULL)
    {
        T = (SearchTree) (malloc(sizeof(struct TreeNode)));
        if (T == NULL) cout << "Out of space !!!";
        else
        {
            T->Element = X;
            T->Left = NULL;
            T->Right = NULL;
        }
    }
    else if (X > T->Element) T->Right = Insert(X, T->Right);
    else if (X < T->Element) T->Left = Insert(X, T->Left);
    // 如果相等就不插入
    return T;
}

// 删除一个元素
SearchTree Delete(ElementType X, SearchTree T)
{
    Position TmpCell;
    if (T == NULL) cout << "Element not found" << endl;
    else if (X < T->Element) T->Left = Delete(X, T->Left);
    else if (X > T->Element) T->Right = Delete(X, T->Right);
    else // 如果找到了要删除的元素
        // (本质上只需要考虑, 右子树为空 和 右子树不为空两种情况)
    if (T->Left != NULL && T->Right != NULL)
    {
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = Delete(T->Element, T->Right);
    } else
    {
        TmpCell = T;
        if (T->Left == NULL) T = T->Right;
        else if (T->Right == NULL) T = T->Left;
        free(TmpCell);
    }
    return T;
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
    int i;
    SearchTree S = NULL;

    // 随机插入一批元素(重复元素不插入)
    for (i = 0; i < 10; i++)
    {
        S = Insert(48 + rand() % 9, S);
    }

    cout << "先序遍历: ";
    PreOrderTraverse(S);
    cout << endl;
    cout << "中序遍历: ";
    InOrderTraverse(S);
    cout << endl;

    cout << "最小元素:" << FindMin(S)->Element << endl;
    cout << "最大元素:" << FindMax(S)->Element << endl;

    cout << "删除一个元素: 1" << endl;
    Delete('1', S);
    cout << "先序遍历: ";
    PreOrderTraverse(S);
    cout << endl;
    cout << "中序遍历: ";
    InOrderTraverse(S);
    cout << endl;

}
