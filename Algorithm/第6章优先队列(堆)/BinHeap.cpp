//
// Created by andy on 16/10/30.
//

#include <iostream>

using namespace std;

#include "BinHeap.h"

int main()
{
    PriorityQueue H = Initialize(10);
    for (int i = 10; i > 0; i--)
    {
        Insert(i, H);
    }
    for (int i = 1; i <= H->size; i++)
    {
        cout << H->Elements[i] << " ";
    }

    cout << endl;
    DeleteMin(H);
    for (int i = 1; i <= H->size; i++)
    {
        cout << H->Elements[i] << " ";
    }

    cout << endl;
    DeleteMin(H);
    for (int i = 1; i <= H->size; i++)
    {
        cout << H->Elements[i] << " ";
    }
    return 0;
}

