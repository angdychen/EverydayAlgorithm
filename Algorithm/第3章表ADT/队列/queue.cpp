//
// Created by andy on 16/6/18.
// 基本数据结构之三: 队列 Queue
//

#include <iostream>

using namespace std;

#include "queue.h"

int main()
{
    Queue queue = CreateQueue();

    cout << "入队: " << endl;
    for (int i = 1; i < 10; i++)
    {
        Enqueue(i, queue);
    }
    TraversalQueue(queue);

    cout << "出队:(带返回值) ";
    cout << Front(queue) << endl;
    TraversalQueue(queue);

    cout << "出队:(无返回值) " << endl;
    Dequeue(queue);
    TraversalQueue(queue);

    cout << "删除整个队列" << endl;
    DisposeQueue(queue);
    TraversalQueue(queue);

    return 0;
}

