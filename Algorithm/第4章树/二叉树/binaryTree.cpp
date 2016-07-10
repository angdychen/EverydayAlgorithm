// 二叉树的定义和基本操作:(二叉树都是递归定义的,基本操作中众多递归思想)
// 1. 创建一颗二叉树
// 2. 先序遍历
// 3. 中序遍历
// 4. 后序遍历
// 5. 层次遍历
// 6. 求二叉树深度
// 7. 求二叉树的宽度
// 8. 求二叉树中结点个数
// 9. 求二叉树第K层节点个数
// 10.求二叉树中叶子节点的个数
// 11.判断两颗二叉树是否相同(相等)
// 测试数据:(下面数据,直接复制粘贴到console即可)
/*
A
B
C
#
#
D
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
//        C  D        F
//                  G
//                H   K
// Created by andy on 16/6/30.
//
#include <iostream>
using namespace std;

#include "BinaryTree.h"

int main()
{
    cout << "Please input TreeNode: " << endl;
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
    cout << endl;

    cout << "2.先序遍历(非递归): ";
    PreOrder2(tree);
    cout << endl;
    cout << "2.先序遍历(解法二): ";
    PreOrder(tree);
    cout << endl;

    cout << "3.中序遍历(非递归): ";
    InOrder(tree);
    cout << endl;

    cout << "4.后序遍历(非递归): ";
    PostOrder(tree);
    cout << endl;

    cout << endl;
    cout << "5.层次遍历(广度优先搜索): ";
    LevelTraverse(tree);
    cout << endl;
    cout << "6.二叉树的深度为(根结点的深度为0): " << GetDepth(tree) - 1 << endl;
    cout << "7.二叉树的宽度为: " << GetWidth(tree) << endl;

    cout << endl;
    cout << "8.二叉树的结点个数为: " << GetNodeNum(tree) << endl;
    cout << "9.二叉树第K层节点个数: " << GetNodeNumKthLevel(tree, 3) << endl;
    cout << "10.二叉树中叶子节点的个数: " << GetLeafNodeNum(tree) << endl;

    cout << endl;
    cout << "Please input the first TreeNode: " << endl;
    Tree P = CreateBinaryTree();
    cout << "Please input the second TreeNode: " << endl;
    Tree Q = CreateBinaryTree();
    cout << "11.判断两颗二叉树是否相同(相等): " << ((IsSameTree(P, Q) == 1) ? "相等" : "不相等") << endl;

    return 0;
}