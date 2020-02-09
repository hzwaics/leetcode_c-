// 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列。

// 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字
// 符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新
// 字符串。

// 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字
// 符串的「公共子序列」是这两个字符串所共同拥有的子序列。

// 若这两个字符串没有公共子序列，则返回 0。

// LCS问题

// 最长公共子序列问题有最优子结构，这个问题可以分解称为更小的问题，因此整个问题就变简单了。
// 同时，子问题的解释可以被重复使用的，也就是说更高级别的子问题会重用更小子问题的解。满足这两点以后，很容易就想到用动态规划来求解

// 1.假设两个字符串s1, s2。当其中一个串的长度为0时，公共子序列的长度肯定为0。
// 2.假设s1的第i个字符与s2的第j个字符相等时，最长子序列等于s1的第i-1个字符与s2的第j-1个字符最长子序列长度+1。
// 3.假设s1的第i个字符与s2的第j个字符不相等时，最长子序列等于s1的第i个字符与s2的第j-1个字符最长子序列长度或s1的第i-1个字符与s2的第j个字符最长子序列长度中最大那一个

// 设dp(i,j) = 0   i==0 || j==0
//           = dp(i-1,j-1)+1    i>0 && j>0 && s1[i] == s2[j]
//           = max( dp(i-1,j), dp(i,j-1) )    i>0 && j>0 && s1[i] != s2[j]

// 典型的二维动态规划


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //异常判断
        if (text1.empty() || text2.empty()) return 0;
        
        int len1 = text1.size(), len2 = text2.size();
        vector<vector<int>> dp(len1, vector<int>(len2,0));

        // 求解边界 BEGIN
        if (text1[0] == text2[0])  dp[0][0] = 1;

        for (int i=1; i<len1; i++) {
            dp[i][0] = dp[i - 1][0];
            if (text1[i] == text2[0]) {  // 排除一下异常情况
                dp[i][0] = 1;
            }

        }
        for (int j=1; j<len2; j++) {
            dp[0][j] = dp[0][j - 1];
            if (text1[0] == text2[j]) { // 排除一下异常情况
                dp[0][j] = 1;
            }
            
        }

        // 求解边界 END
        for (int i = 1; i < len1; i++)
            for (int j = 1; j < len2; j++) {
                if (text1[i] == text2[j]) {  // 遇到匹配字符
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {  // 不匹配时，继承左上中的较大值
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }

        return dp[len1-1][len2-1];

    }
};


// 状态压缩后
// 参考leetcode上的解法，待消化--TODO
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int cols = text2.size();
        vector<int> dp(cols, 0);
        // 一次性将text1的当前字符值取出来，避免重复数组操作
        // 优化到这里终于双100%击败其他用户了 ORZ
        for (const auto ti : text1) {
            int last = dp[0];
            if (ti == text2[0]) {
                dp[0] = 1;
            }

            for (int j = 1; j < cols; j++) {
                if (ti == text2[j]) {
                    swap(dp[j], last);
                    dp[j]++;
                } else {
                    last = dp[j];
                    if (dp[j - 1] > dp[j])
                        dp[j] = dp[j - 1];
                }
            }
        }
        return dp[cols - 1];
    }
};

