//
// Created by andy on 16/6/6.
//  基本数据结构之一: 链表List
//
#include <iostream>
using namespace std;
#include "list.h"

int main()
{
    List list = MakeEmpty();
    for(int i=1; i<6; i++) {
        Insert(i, list);
    }

    Insert(100, list, FindLast(list));
    TraversalList(list);

    Delete(100, list);
    TraversalList(list);

    Delete(3, list);
    TraversalList(list);

    Position TmpCell = Find(100, list) ;
    TmpCell== NULL ? cout << "\n未找到元素" <<endl
                   : cout<< "\n所查找元素为:"<< TmpCell->data << endl;


    cout << "\n单链表反转:" << endl;
    Reverse(list);
    TraversalList(list);

    DeleteList(list);
    TraversalList(list);

    return 0;
}



