//
// Created by andy on 16/5/29.
// 折半查找: 时间复杂度 o(logn)

#include <iostream>
using namespace std;

int binarySearch(int A[], int n, int element)
{
    int start = 0, end = n-1;
    int mid;
    while(start <= end)
    {   mid = (start+end)/2;
        if(A[mid] == element)
            return mid;
        else if(A[mid] > element) end = mid-1;
            else start = mid+1;
    }
    return -1;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6};
    cout <<" 元素下标为: " <<binarySearch(array, 6, 6);
}

