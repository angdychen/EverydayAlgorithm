//
// Created by andy on 16/5/29.
// 在我们的例子中,最大子序列和可能出三处出现。或者整个出现在输入数据的左半部分,或者出现在右半部分,
// 或者跨越输入数据的中部从占据数据左右两半部分。

#include <iostream>

using namespace std;

//算法三: 时间复杂度:O(n*logn)
int max3(int a, int b, int c)
{
    if (a > b) b = a;
    return b > c ? b : c;
}

int maxSubSum(int A[], int left, int right)
{
    int maxLeftSum, maxRightSum;
    int maxLeftBorderSum, maxRightBorderSum;
    int leftBorderSum, rightBorderSum;
    int center, i, result;

    if (left == right)
    {
        return A[left];
    }

    center = (left + right) / 2;
    // 第一种可能(出现在左半部分)
    maxLeftSum = maxSubSum(A, left, center);
    // 第二种可能(出现在左半部分)
    maxRightSum = maxSubSum(A, center + 1, right);

    // 第三种可能: <1.> (包含左半部分右边界的部分)
    maxLeftBorderSum = 0;
    leftBorderSum = 0;
    for (i = center; i >= left; i--)
    {
        leftBorderSum += A[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    // 第三种可能: <2.> (包含右半部分左边界的部分)
    maxRightBorderSum = 0;
    rightBorderSum = 0;
    for (i = center + 1; i <= right; i++)
    {
        rightBorderSum += A[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    // 比较三种可能中,哪一种最大
    result = max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
    cout << left << ", " << right << "递归到此处了," << "maxLeft: " << maxLeftSum << ", maxRight: " << maxRightSum
    << ", maxBorder: " << maxLeftBorderSum + maxRightBorderSum << ", Max:" << result << endl;
    return result;

}

//算法四: 时间复杂度:O(n)
int MaxSubsequenceSum(const int A[], int N)
{
    int ThisSum, MaxSum, j;
    ThisSum = MaxSum = 0;
    for (j = 0; j < N; j++)
    {
        ThisSum += A[j];
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
            // 此时ThisSum<0,最小子序列的和必从下一项开始算起
            // 4,3,2,1,-1,-2,-3,-4,-5,0,1,2,3
            // ||------------------||(ThisSum<0)
        else if (ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}

int main()
{
    int array[] = {4, -3, 5, -2, -1, 2, 6, -2};
    int result = maxSubSum(array, 0, 7);
    cout << "算法三: " << result << endl;
    cout << "算法四: " << MaxSubsequenceSum(array, 7);
    return 0;
}

