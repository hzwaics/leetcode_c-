// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

// 动态规划的核心：
// dp方程：f(n) 与 f(n-1)、f(n-2)的关系

// 爬楼梯中，设dp(i)为到达i阶楼梯的方法
// 则dp(i) = dp(i-1) + dp(i-2)

class Solution {
public:
    int climbStairs(int n) {
        int dp1 = 1, dp2 = 2, dpn = 0;

        if (n==1) return dp1;
        if (n==2) return dp2;

        for (int i=3; i<=n; i++) {
            dpn = dp2 + dp1;
            dp1 = dp2;
            dp2 = dpn;
        }

        return dpn;
    }
};

