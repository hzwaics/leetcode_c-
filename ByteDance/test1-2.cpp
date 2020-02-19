// 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

// 动态规划解法：
// if (grid[i][j] == 1) f[i][j] = min(f[i-1][j-1], f[i-1][j], f[i][j-1]) + 1;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int rowSize = matrix.size();
        if (rowSize == 0){
            return 0;
        }
        int colSize = matrix[0].size();
        if (colSize == 0){
            return 0;
        }

        int maxRes = 0;//最大的正方形边长

        vector<vector<int>> dp(rowSize+1, vector<int>(colSize+1, 0));

        for (int row=1; row<=rowSize; ++row) {
            for (int col=1; col<=colSize; ++col) {
                if (matrix[row-1][col-1] == '1') {
                    dp[row][col] = min(dp[row-1][col-1], min(dp[row-1][col], dp[row][col-1])) + 1;
                    maxRes = max(maxRes, dp[row][col]);
                }
            }
        }

        
        return maxRes*maxRes;
    }
};

