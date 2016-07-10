//
// Created by andy on 16/7/10.
//

#ifndef ALGORITHM_BINARYTREE_H
#define ALGORITHM_BINARYTREE_H

#include <iostream>

using namespace std;

#include <stack>
#include <queue>

/****************** 数据结构 ********************/
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

/****************** 函数定义 ********************/
Tree CreateBinaryTree(void);

void PreOrderTraverse(Tree T);

void PreOrder(Tree T);

void PreOrder2(Tree T);

void InOrderTraverse(Tree T);

void InOrder(Tree T);

void PostOrderTraverse(Tree T);

void PostOrder(Tree T);

void LevelTraverse(Tree T);

int GetDepth(Tree T);

int GetWidth(Tree T);

int GetNodeNum(Tree T);

int GetNodeNumKthLevel(Tree T, int K);

int GetLeafNodeNum(Tree T);

bool IsSameTree(Tree P, Tree Q);

/****************** 函数实现 ********************/

// 1.创建二叉树
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

// 2.先序遍历(递归版)
void PreOrderTraverse(Tree T)
{
    if (T != NULL)
    {
        cout << T->Element << " ";
        PreOrderTraverse(T->Left);
        PreOrderTraverse(T->Right);
    }
}

// 2.先序遍历(非递归版)
void PreOrder(Tree T)
{
    stack<PtrToNode> stackNode;
    PtrToNode node = T;
    while (node != NULL || !stackNode.empty())
    {
        if (node != NULL)
        {
            cout << node->Element << " ";
            stackNode.push(node);
            node = node->Left;
        }
        else
        {
            node = stackNode.top();
            stackNode.pop();
            node = node->Right;
        }
    }
}

// 2.先序遍历(非递归版)第二种解法
void PreOrder2(Tree T)
{
    stack<PtrToNode> stack;
    PtrToNode node;
    if (T != NULL) stack.push(T);
    while (!stack.empty())
    {
        node = stack.top();
        stack.pop();
        cout << node->Element << " ";
        if (node->Right != NULL) stack.push(node->Right);
        if (node->Left != NULL) stack.push(node->Left);
    }
}

// 3.中序遍历(递归版)
void InOrderTraverse(Tree T)
{
    if (T != NULL)
    {
        InOrderTraverse(T->Left);
        cout << T->Element << " ";
        InOrderTraverse(T->Right);
    }
}

// 3.中序遍历(非递归)
void InOrder(Tree T)
{
    stack<PtrToNode> stackNode;
    PtrToNode node = T;
    while (node != NULL || !stackNode.empty())
    {
        if (node != NULL)
        {
            stackNode.push(node);
            node = node->Left;
        }
        else
        {   // 弹出元素直接找其右边的元素
            node = stackNode.top();
            stackNode.pop();
            cout << node->Element << " ";
            node = node->Right;
        }
    }
}

// 4.后序遍历(递归版)
void PostOrderTraverse(Tree T)
{
    if (T != NULL)
    {
        PostOrderTraverse(T->Left);
        PostOrderTraverse(T->Right);
        cout << T->Element << " ";
    }
}

// 4.后序遍历(非递归,后序遍历的非递归实现是三种遍历方式中最难的一种)
void PostOrder(Tree T)
{
    stack<PtrToNode> stackNode;
    PtrToNode previous = NULL;   // 上一次访问位置
    PtrToNode current;           // 当前结点
    stackNode.push(T);
    while (!stackNode.empty())
    {
        current = stackNode.top();
        if ((current->Left == NULL && current->Right == NULL)
            || (previous != NULL && (previous == current->Left || previous == current->Right)))
        {
            cout << current->Element << " ";
            stackNode.pop();
            previous = current;
        } else
        {
            // 如果不满足上面两种情况,则将其右孩子,左孩子依次入栈
            //  (一定注意顺序,必须先右孩子入栈,再左孩子入栈)
            if (current->Right != NULL)
                stackNode.push(current->Right);
            if (current->Left != NULL)
                stackNode.push(current->Left);
        }
    }
}

// 5.层次遍历(原本以为好难,写起来原来这么简单,so easy)
/* 1.相当于广度优先搜索,使用队列实现。
 * 2.先将根节点入队
 * 3.队列不为空时,弹出一个节点
 * 4.将其左结点入队,再将其右结点入队
 * 5.循环执行,直到队列为空
 * */
void LevelTraverse(Tree T)
{
    queue<PtrToNode> queueNode;
    PtrToNode node;
    if (T != NULL) queueNode.push(T);
    while (!queueNode.empty())
    {
        node = queueNode.front();
        queueNode.pop();
        cout << node->Element << " ";
        if (node->Left != NULL)
            queueNode.push(node->Left);
        if (node->Right != NULL)
            queueNode.push(node->Right);
    }
}

// 6.求解二叉树的深度
/*     假设已知一颗二叉树的左子树和右子树的深度,怎么算出整棵树的深度呢?这是问题的关键。
 * 如果有一颗二叉树,左子树的深度为leftDepth,右子树的深度为rightDepth, 则整棵树的深度
 * 就是max(leftDepth, rightDepth)+1, 即左子树与右子树深度的最大值加上1。
 *     因此这个求深度的过程就是先求左子树的深度,再求右子树的深度,然后返回两者之中最大值
 * 加 1 就是整棵树的深度。这正对应于先遍历左子树(得到leftDepth),再遍历右子树(得到right
 * -Depth),最后访问根(得到整棵树的深度为max(leftDepth, rightDepth)+1)的后序遍历方式。
 * */
int GetDepth(Tree T)
{
    int leftDepth = 0, rightDepth = 0;
    if (T == NULL) return 0;    // T == NULL 条件
    else
    {
        leftDepth = GetDepth(T->Left);
        rightDepth = GetDepth(T->Right);
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}

// 7.求解二叉树的宽度(类似于层次遍历算法)
/*
 * 此方法甚好理解*/
int GetWidth(Tree T)
{
    queue<PtrToNode> queueNode;
    PtrToNode node;
    int currentWidth = 1;            // 当前层结点的宽度
    int nextWidth = 0;               // 下一层结点的宽度
    int maxWidth = currentWidth;     // 最大宽度
    if (T != NULL) queueNode.push(T); else return 0;
    while (!queueNode.empty())
    {
        while (currentWidth > 0)
        {
            node = queueNode.front();
            queueNode.pop();
            currentWidth--;

            if (node->Left != NULL)
            {
                queueNode.push(node->Left);
                nextWidth++;
            }
            if (node->Right != NULL)
            {
                queueNode.push(node->Right);
                nextWidth++;
            }
        }
        currentWidth = nextWidth;
        if (currentWidth > maxWidth) maxWidth = currentWidth;
        nextWidth = 0;
    }
    return maxWidth;
}
// 8.求解二叉树结点个树
/* 递归解法：
（1）如果二叉树为空，节点个数为0
（2）如果二叉树不为空，二叉树节点个数 = 左子树节点个数 + 右子树节点个数 + 1
 */
int GetNodeNum(Tree T)
{
    if (T == NULL) return 0;
    return GetNodeNum(T->Left) + GetNodeNum(T->Right) + 1;
}

// 9. 求二叉树第K层节点的个数
/*递归解法：
（1）如果二叉树为空或者k<1返回0
（2）如果二叉树不为空并且k==1，返回1
（3）如果二叉树不为空且k>1，返回左子树中k-1层的节点个数与右子树k-1层节点个数之和
 * */
int GetNodeNumKthLevel(Tree T, int K)
{
    if (T == NULL || K < 1) return 0;
    if (K == 1) return 1;
    return GetNodeNumKthLevel(T->Left, K - 1) + GetNodeNumKthLevel(T->Right, K - 1);
}

// 10.求解二叉树中叶子节点的个数
/*递归解法：
（1）如果二叉树为空，返回0
（2）如果二叉树不为空且左右子树为空，返回1
（3）如果二叉树不为空，且左右子树不同时为空，返回左子树中叶子节点个数加上右子树中叶子节点个数
 * */
int GetLeafNodeNum(Tree T)
{
    if (T == NULL) return 0;
    if (T->Left == NULL && T->Right == NULL) return 1;
    return GetLeafNodeNum(T->Left) + GetLeafNodeNum(T->Right);
}

// 11.判断两颗二叉树是否相同(相等)
/*递归解法:
 * (1) 如果 p==NULL && q==NULL,相等
 * (2) 1. 如果 p==NULL && q!=NULL
 *     2. 或者 p!=NULL && q = NULL,
 *     3. 或者 p.data!=q.data , 不相等
 * (3) 如果 p.data = q.data, 则递归
 * */
bool IsSameTree(Tree P, Tree Q)
{
    if (P == NULL && Q == NULL) return true;
    if ((P == NULL && Q != NULL) || (P != NULL && Q == NULL)) return false;
    if (P->Element != Q->Element) return false;
    return IsSameTree(P->Left, Q->Left) && IsSameTree(P->Right, Q->Right);
}

#endif //ALGORITHM_BINARYTREE_H
