//
// Created by andy on 16/5/28.
//

#include <iostream>
using namespace std;

// 算法一:递归算法 时间复杂度: c^n 指数级别
//     (3/2)^i < F(i) < (5/3)^ i
// 最糟糕的递归方式之一
int fib(int n)
{
    if(n<=1) return 1;
    else
        return fib(n-1) + fib(n-2);
}

// 算法二:迭代 时间复杂度: O(n)
int fibLoop(int n)
{
    while(n<=0)
        return 0;
    int a = 0, b =1;
    int temp = 0;
    while (n--)
    {
        temp = b;
        b = a+b;
        a = temp;
    }
    return b;
}

int main()
{
    int n;
    cout << "裴波那契数列: " << endl;
    cin >> n;
    cout <<"算法二:迭代 " << fibLoop(n) << endl;
    cout <<"算法一:递归 " << fib(n) << endl;
    return 0;
}
