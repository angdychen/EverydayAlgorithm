//
// Created by andy on 16/5/22.
/*问题描述：
　　有一个梵塔，塔内有三个座A、B、C，A座上有诺干个盘子，盘子大小不等，大的在下，小的在上（如图）。
把这些个盘子从A座移到C座，中间可以借用B座但每次只能允许移动一个盘子，并且在移动过程中，3个座上的盘
子始终保持大盘在下，小盘在上。
描述简化：把A柱上的n个盘子移动到C柱，其中可以借用B柱。*/
//
#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node * next;
} Node;

// 1.采用递归的方法
//
// 1.将f(n-1)个盘子从a －》 b
// 2.把第n个盘子放到c上
// 3.把b上面的n-1个盘子，放到c
// 》》》》所有盘子都已到了c
//
int  HanoiTower(int n, char source, char temp, char target)
{
    if(n == 1)
    {
        cout << source << "->" << target << endl;
        return 1;
    }
    HanoiTower(n-1, source, target, temp); 		// 将f(n-1)个盘子从a －》 b
    cout << source << "->" << target << endl;
    HanoiTower(n-1, temp, source, target);
}

// 2.非递归的方
int main()
{
    int num = 3;
   cout << HanoiTower(num, 'A', 'B', 'C') << endl;

    cout<<"normal:"<<endl;
    int n;
    cin >> n;

    // 最多2256个盘子
    char order[2][256];
    char pos[64];

    order[0]['A'] = 'B';
    order[0]['B'] = 'C';
    order[0]['C'] = 'A';

    order[1]['A'] = 'C';
    order[1]['B'] = 'A';
    order[1]['C'] = 'B';

    //0是顺序 1是逆序
    int index[64];
    int count =0 ; // 移动次数

    //确定轨迹的顺序还是逆序
    int i, j, m;
    for(i = n; i > 0; i -= 2)
        index[i] = 1;

    for(i = n - 1; i > 0; i -= 2)
        index[i] = 0;

    memset(pos, 'A', sizeof(pos));
    cout << "sizeof(pos) " << sizeof(pos) << endl;

    for(i = 1; i < (1 << n); i ++)
    {
        for(m = 1, j = i; j%2 == 0; j/=2, m ++);
        cout << m <<" : "<< pos[m]  <<" --> " << order[index[m]][pos[m]] << endl;
        pos[m] = order[index[m]][pos[m]];
        count++;
    }
    cout << "总移动次数: " << count << endl;

    return 0;
}

