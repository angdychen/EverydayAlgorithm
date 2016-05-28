/***************************************************************************************************
 * 【问题提出】
 *  在一次学生会主席的选举中，每人投一票，如果有某候选人超过半数，则该人可直接当选。
 * 【相关概念】
 *  在一个规模为N的数组array[N]中，所谓主元素就是出现次数大于N/2的元素，例如
 *  a[10]=(3,3,4,2,4,4,2,4,4,4),  有一个主元素为4。
 *  给出一个算法，如果主元素存在，则输出主元素，否则输出没有主元素。
 *
 * 【相关题目】
 *  2013年硕士研究生入学考试计算机专业基础综合408，综合应用第一题。
 *
 * 【算法设计】
 * 　　
 *  [常规想法]：
 *
 *  (1)穷举：找出元素中每一个数在数据中的数量。时间复杂度O(N^2)；
 *  (2)排序：先对数组快排，然后重头开始遍历一遍计算每个数的数量。时间复杂度O(N*logN+N)；o(nlogn)
 *
 *  [其他算法] ：
 *
 *  (3)裁剪数组算法, 时间复杂度为O(2*N) （From：http://hxraid.iteye.com/blog/664449）
 *      思想：如果一个数组array[N]，其中有两个元素e1和e2。
 *   (a)e1不等于e2
 *          假如e1是数组array[N]的主元素，e2不是。那么e1在array[N]中的数量en>N/2。此时
 *      去掉array[N]中的e1和e2两个元素(e1!=e2)。那么新数组array[N-2]中e1的数量为en-1，
 *      并且en-1 > N/2-1 = (N-2)/2。即e1还是新数组array[N-2]的主元素。
 *          假如e1和e2都不是数组array[N]的主元素，那么去掉e1、e2以后。那么新数组的大小将变
 *      成N-2。此时很有可能出现一个新数组的主元素X，此主元素X的数量正好等于X =(N-2)/2+1。但
 *      是该主元素就不是原数组的主元素了，因为X= (N-2)/2+1=N/2。那么这样的主元素X我们叫做伪
 *      主元素。因此需要通过和裁剪掉元素比较，来确定是否是真正的主元素。
 *   (b)e1等于e2
 *      这种情况下不能进行裁剪。只能继续找不同的两个数裁减掉。
 *
 *  (4)递推法（From：http://www.cnblogs.com/microsoftmvp/archive/2012/10/29/2745598.html）
 *      我们比较a[0]和a[1]，（如果相等，存起来）比较a[2]和a[3]（如果相等，存起来）......按照
 *      这个过程，将得到一个新的数组，如果这个数组的元素个数为0，那么寻找候选者失败，宣告数组a没
 *      主元；否则我们递归的处理新得到的数组，最终要么在某步里宣告主元不存在，要么得到唯一的一个
 *      元素，这个元素就是候选者。接着，判断这个候选者是否是主元就ok了。
 *
 *   说明：
 *   1、如果数组a的大小是奇数呢？哦，那么可以成对比较前面的偶数个元素，最后一个单独称为候选者，和前
 *      面偶数个产生的候选者一起，加入到最后“审判”的队伍中来。可以证明，这不影响算法的正确性。
 *   2、按照这个算法的描述，似乎空间复杂度是O(n)，但是我们可以充分利用数组a，为什么？
 *   3、这个算法的时间复杂度并不明显，但是利用递推公式则很容易解出。
*******************************************************************************************************/


#include <iostream>
using namespace std;

#define NO_MAJORITY INT_MIN


// 算法一:穷举法
static int majEle_exhaust(int a[], int n)
{
    int i,j;
    int count = 0;
    for(i=0; i<= n/2; i++)
    {
        count = 0;
        for(j=i; j<=n; j++)
        {
            if(a[i] == a[j])    count++;
            if(count>n/2) return a[i];
        }
    }
    return NO_MAJORITY;
}

// 算法三: 裁减数组 时间复杂度 O(N)
static int majEle_loop(int a[], int n)
{
    int element = a[0];
    int *dArr = new int[n];
    int count = 0;  // 裁减过程中遇到相同元素的个数
    int del = 0;    // 纪录删除元素的个数
    int dTop = 0;   // 当前裁减数组的索引位置

    for(int i=0; i<n; i++)
    {
        if(count==0) element = a[i];

        if(a[i] == element)         // 如果相邻的元素相等
            count++;
        else if(count>0)            // 如果相邻的元素不相等,则需要裁减得到新的数组
        {
            dArr[dTop++] = element;
            dArr[dTop++] = a[i];
            del =  del + 2;
            count--;
        }
    }

    // 如果裁减之后出现了主元素,那么这个主元素有可能是个伪主元素
    if(count>(n-del)/2)
    {
        // 与裁减的数组元素一一比较
        for(int j=0; j<del; j++)
        {
            if(element==dArr[j]) count++;
            // 确定真正的主元素
            if(count>n/2) return element;
        }
    }

    return NO_MAJORITY;
}

// 算法四: 递推法
static int majEle_recursice(int a[], int n)
{
    int i, j, k = n/2;
    int temp = NO_MAJORITY;

    if(n==0) return (NO_MAJORITY);  // 如果[0,1] [2,3] 。。。没有出现任何一对相同元素,对于偶数长度数组则必无主元,奇数(判断最后一个元素)
    if(n==1) return a[0];

    for(i=0, j=0; i<k; i++)
    {
        if(a[2*i] == a[2*i+1])
        {
            temp = a[j];
            a[j++] = a[2*i];
            a[2*i] = temp;
        }
    }

    temp = majEle_recursice(a, j);  // 递推的过程中只要出现了NO_MAJORITY就是没有主元存在(奇数长度另外判断)

    if(n%2==1 && temp == NO_MAJORITY) temp = a[n-1];

    if(temp != NO_MAJORITY)
    {
        int count = 0;
        for(int k=0; k<n; k++)
        {
            if(a[k]==temp)
                count++;
        }
        if(count<=n/2) return NO_MAJORITY;
    }
    return temp;
}

int main() {
    int a[9] = {1,2,2,1,2,9,2,5,3};
    cout << "majEle_exhaust: " << majEle_exhaust(a, 9) << endl;
    cout << "majEle_recursice: " << majEle_recursice(a, 9) << endl;
    cout << "majEle_loop: " << majEle_loop(a, 9) << endl;
}

