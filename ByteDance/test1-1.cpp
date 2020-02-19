// 给一个数组，找出乘积最大的子数组

// 输入: [-2,0,-1]
// 输出: 0
// 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

// 输入: [2,3,-2,4]
// 输出: 6
// 解释: 子数组 [2,3] 有最大乘积 6。


// 动态规划思路：

// 设: dp[i][0]代表此位置当前最大的乘积
//     dp[i][1]代表此位置当前最小的乘积
// dp[i][0] = Math.max(Math.max(dp[i-1][0] * nums[i], nums[i]), dp[i-1][1] * nums[i]);
// dp[i][1] = Math.min(Math.min(dp[i-1][0] * nums[i], nums[i]), dp[i-1][1] * nums[i]);

// 对dp[i][0]：
// 1.如果dp[i-1][0] >1，且num[i] > 0, Max() 返回dp[i-1][0] * nums[i]
// 2.如果dp[i-1][0]是负数，且num[i] < 0, Max() 返回dp[i-1][1] * nums[i]
// 3.如果dp[i-1][0] < 1，且num[i] > 0 Max() 返回 num[i]    


// 动态规划方程：
// maxend = max(max(maxend * a[i], minend * a[i]), a[i]);
// minend = min(min(maxend * a[i], minend * a[i]), a[i]); 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int maxEnd = nums[0], minEnd = nums[0], maxResult = nums[0];
        int tmp1, tmp2;

        for (int i=1; i<len; i++) {
            tmp1 = maxEnd*nums[i];
            tmp2 = minEnd*nums[i];
            maxEnd = Math.max(Math.max(tmp1, tmp2), a[i]);
            minEnd = Math.min(Math.min(tmp1, tmp2), a[i]);
            maxResult = Math.max(maxEnd, maxResult);
        }

        return maxResult;
    }
};



