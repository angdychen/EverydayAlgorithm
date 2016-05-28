//
// Created by andy on 16/5/29.
// 在我们的例子中,最大自序列和可能出三处出现。或者整个出现在输入数据的左半部分,或者出现在右半部分,
// 或者跨越输入数据的中部从占据数据左右两半部分。

#include <iostream>
using namespace std;

//算法三: 时间复杂度:O(n*logn)
int max3(int a, int b, int c)
{
    if(a>b) b =  a;
    return b > c ? b : c;
}

int maxSubSum(int A[], int left, int right)
{
    int maxLeftSum, maxRightSum;
    int maxLeftBorderSum, maxRightBorderSum;
    int leftBorderSum, rightBorderSum;
    int center, i, result;

    if(left == right)
    {
      return A[left];
    }

    center = (left + right)/2;
    maxLeftSum = maxSubSum(A, left, center);
    maxRightSum = maxSubSum(A, center+1, right);

    maxLeftBorderSum = 0;   leftBorderSum = 0;
    for(i = center; i >= left; i--)
    {
        leftBorderSum += A[i];
        if(leftBorderSum>maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    maxRightBorderSum = 0; rightBorderSum = 0;
    for(i = center+1; i<=right; i++)
    {
        rightBorderSum += A[i];
        if(rightBorderSum>maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    result = max3(maxLeftSum, maxRightSum, maxLeftBorderSum+maxRightBorderSum);
    cout << left << ", " << right <<"递归到此处了," << "maxLeft: "<< maxLeftSum <<", maxRight: " << maxRightSum
        << ", maxBorder: " << maxLeftBorderSum+ maxRightBorderSum << ", Max:" << result << endl;
    return result;

}

int main()
{
    int array[] = {4, -3, 5, -2, -1, 2, 6, -2};
    cout << maxSubSum(array, 0, 7) << endl;
    return 0;
}

