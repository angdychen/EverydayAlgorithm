// 二叉树的定义和基本操作:
// 1. 创建一颗二叉树
// 2. 先序遍历
// 3. 中序遍历
// 4. 后序遍历
// 5. 层次遍历
// 6. 求二叉树深度
// 7. 求二叉树的宽度
// 8. 求结点个数
// 测试数据:A↙ B↙ *↙ C↙ D↙ *↙ *↙ *↙ E↙ *↙ F↙ G↙ H↙ *↙ *↙ K↙ *↙ *↙ *↙(下面数据,直接复制粘贴到console即可)
/*
A
B
#
C
D
#
#
#
E
#
F
G
H
#
#
K
#
#
#
*/
//              A
//          B       E
//            C       F
//          D       G
//                H   K
// Created by andy on 16/6/30.
//

#include <iostream>

using namespace std;

#include <stdlib.h>


// 定义结点 与 树 (本质相同,表示方法不同)
typedef struct TreeNode *PtrToNode;
typedef PtrToNode Tree;
typedef char ElementType;

// 二叉树(数据结构的定义)
struct TreeNode
{
    ElementType Element;    // 数据域
    PtrToNode Left;              // 左结点
    PtrToNode Right;            // 右结点
};

// 创建二叉树
Tree CreateBinaryTree(void)
{
    ElementType data;           // 定义数据区
    PtrToNode ptr;              // 定义结点
    cin >> data;                // 输入数据(回车 结束)
    if (data == '#')
        ptr = NULL;
    else
    {
        ptr = (PtrToNode) malloc(sizeof(struct TreeNode));
        ptr->Element = data;
        ptr->Left = CreateBinaryTree();
        ptr->Right = CreateBinaryTree();
    }
    return ptr;
}

// 先序遍历
void PreOrderTraverse(Tree T)
{
    if (T != NULL)
    {
        cout << T->Element << " ";
        PreOrderTraverse(T->Left);
        PreOrderTraverse(T->Right);
    }
}

// 中序遍历
void InOrderTraverse(Tree T)
{
    if(T != NULL)
    {
        InOrderTraverse(T->Left);
        cout << T->Element << " ";
        InOrderTraverse(T->Right);
    }
}

// 后序遍历
void PostOrderTraverse(Tree T)
{
    if( T != NULL)
    {
        PostOrderTraverse(T->Left);
        PostOrderTraverse(T->Right);
        cout << T->Element << " ";
    }
}

int main()
{
    Tree tree = CreateBinaryTree();

    cout << "2.先序遍历(递归版): ";
    PreOrderTraverse(tree);
    cout << endl;

    cout << "3.中序遍历(递归版): ";
    InOrderTraverse(tree);
    cout << endl;

    cout << "4.后序遍历(递归版): ";
    PostOrderTraverse(tree);
    cout << endl;

    return 0;
}