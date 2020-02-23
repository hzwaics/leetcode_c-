// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
// 输入: "babad"
// 输出: "bab"
// 注意: "aba" 也是一个有效答案。

// 状态转移：
// 设dp[i][j]表示s[i..j]是否是回文，是为ture/不是为false（bool型）

// 参考：https://www.jianshu.com/p/a7741619dd58



class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return s;    

        int len = s.size();

        bool dp[len][len];  //dp[i][j]表示s[i..j]是否是回文
        memset(dp, 0, sizeof(dp));

        int left=0, right=0;
        for (int i=len-2; i>=0; i--) {
            dp[i][i] = true;

            for (int j=i+1; j<len; j++) {
                dp[i][j] = (s[i]==s[j]) && (j-i<3 || dp[i+1][j-1]);
                if (dp[i][j] && ((right-left)<(j-i))) {
                    left = i;
                    right = j;
                }
            }
        }

        return s.substr(left, right);
        
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        
    const int len = s.size();
        if(len <= 1)return s;
        bool dp[len][len];//dp[i][j]表示s[i..j]是否是回文
        memset(dp, 0, sizeof(dp));
        int resLeft = 0, resRight = 0;
        dp[0][0] = true;
        for(int i = 1; i < len; i++)
        {
            dp[i][i] = true;
            dp[i][i-1] = true;//这个初始化容易忽略，当k=2时要用到
        }
        for(int k = 2; k <= len; k++)//枚举子串长度
            for(int i = 0; i <= len-k; i++)//枚举子串起始位置
            {
                if(s[i] == s[i+k-1] && dp[i+1][i+k-2])
                {
                    dp[i][i+k-1] = true;
                    if(resRight-resLeft+1 < k)
                    {
                        resLeft = i;
                        resRight = i+k-1;
                    }
                }
            }
        return s.substr(resLeft, resRight-resLeft+1);
    }
};



