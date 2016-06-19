//
// Created by andy on 16/6/18.
// 基本数据结构之二: 堆栈 Stack
//
#include <iostream>
using namespace std;

#include "stack.h";

int main()
{
    Stack stack = CreateStack();
    for (int i = 1; i < 7; i++)
    {
        Push(i, stack);
    }

    ElementType element = Top(stack);
    cout << "Top弹栈:" << element << endl;

    cout << "Pop弹栈:" << endl;
    Pop(stack);

    cout << "堆栈遍历:" << endl;
    TraversalStack(stack);

    cout << "清空堆栈" << endl;
    DisposeStack(stack);
    TraversalStack(stack);
    return 0;
}
