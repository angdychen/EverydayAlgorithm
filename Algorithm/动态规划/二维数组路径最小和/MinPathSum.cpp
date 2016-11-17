//
// Created by andy on 16/11/15.
//

#include <iostream>
#include <vector>

using namespace std;

// 最经典的动态规划的例子
int minPathSum(vector<vector<int>> &grid)
{
    // 二维数组的行 和 列
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp<m, vector<int>(n)>;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0)
            {
                if (j == 0) dp[i][j] = grid[i][j];
                else
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
            }
            else if (j == 0)
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[m - 1][n - 1];
}

// 对其空间复杂度优化后 O(n)
int minPathSum1(vector<vector<int>> &grid)
{
    // 二维数组的行 和 列
    int m = grid.size(), n = grid[0].size();
    vector<int> dp(n);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0)
            {
                if (j == 0) dp[j] = grid[i][j];
                else
                    dp[j] = dp[j - 1] + grid[i][j];
            }
            else if (j == 0)
                dp[j] = dp[j] + grid[i][j];
            else
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
        }
    }
    return dp[n - 1];
}