//
// Created by andy on 16/6/16.
//

#include <iostream>

using namespace std;

#include "polynomial.h"

int main()
{
    Polynomial polynomial1 = MakeEmpty();
    Polynomial polynomial2 = MakeEmpty();

    // 构建多项式1
    for (int i = 3; i < 8; i = i + 2)
    {
        PtrToNode node = (PtrToNode) malloc(sizeof(struct Node));
        node->Coefficient = i;  // 系数
        node->Exponent = i;     // 指数
        node->Next = NULL;
        InsertNode(node, polynomial1);
    }

    // 构建多项式2
    for (int i = 0; i < 10; i = i + 3)
    {
        PtrToNode node = (PtrToNode) malloc(sizeof(struct Node));
        node->Coefficient = i;  // 系数
        node->Exponent = i;     // 指数
        node->Next = NULL;
        InsertNode(node, polynomial2);
    }

    TraversalPolynomial(polynomial1);
    TraversalPolynomial(polynomial2);

    cout << "" << endl;
    cout << "多项式加法:" << endl;

    TraversalPolynomial(AddPolynomial(polynomial1, polynomial2));

    cout << "" << endl;
    cout << "多项式减法:" << endl;
    TraversalPolynomial(SubPolynomial(polynomial1, polynomial2));

    cout << "" << endl;
    cout << "多项式乘法:" << endl;
    TraversalPolynomial(MultPolynomial(polynomial1, polynomial2));


    return 0;
}