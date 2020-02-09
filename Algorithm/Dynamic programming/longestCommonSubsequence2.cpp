// 最长公共子串（动态规划）
// 参考：https://www.cnblogs.com/fanguangdexiaoyuer/p/11281179.html

// 和子序列相比，子串必须是字符之间彼此连续的

// 解析：
// 1、把两个字符串分别以行和列组成一个二维矩阵。
// 2、比较二维矩阵中每个点对应行列字符中否相等，相等的话值设置为1，否则设置为0。
// 3、通过查找出值为1的最长对角线就能找到最长公共子串。

// 为了进一步优化算法的效率，我们可以再计算某个二维矩阵的值的时候顺便计算出来当前最长的公共子串的长度，
// 即某个二维矩阵元素的值由record[i][j]=1演变为record[i][j]=1 +record[i-1][j-1]，这样就避免了后续查找对角线长度的操作了。

// 递推公式为：
// 设dp(i,j)为s1[i]和s2[j]的最长公共子串
// dp(i,j) = 0                i==0 || j==0
//         = dp(i-1,j-1)+1    s1[i]==s[j]
//         = 0                s1[i]!=s[j]

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //异常判断
        if (text1.empty() || text2.empty()) return 0;

        int len1 = text1.size(), len2 = text2.size();
        // vector<vector<int>> dp(len1, vector<int>(len2,0));
        int[][] dp = new int[len1][len2];
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (text1[i] == text2[j]) {
                    if (i==0 || j==0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }

                    result = Math.max(dp[i][k], result);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return result;
    }
};

