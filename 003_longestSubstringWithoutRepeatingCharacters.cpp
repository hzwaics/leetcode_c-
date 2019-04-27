// 3种解法：
// 前两种参考：https://blog.csdn.net/qq_17550379/article/details/80547777
// 1) 从字符串开始遍历，找出每个字符的最大不重复字符串长度，然后比较给出最大值
//    这个最好理解也最直观，但时间复杂度是O(n2)，空间复杂度O(n)
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        maxLength = 0 //记录最大长度
        for i,s_str in enumerate(s):
            tempLenth = 0 //记录每个子串最大长度
            tempStr = str() //保存每次遍历的最长子串
            for j in s[i:]:
                if j not in tempStr:
                    tempStr += j
                    tempLenth += 1
                    
                    if tempLenth >= maxLength:
                        maxLength = tempLenth

                else:
                    break
        
        return tempLenth

// 2) 第二种思路：一般像嵌套for循环的这种，要思考下能否用hashmap去做，
//    保证只有一个for循环，降低时间复杂度到O(n)。具体要看题目的解决思路
//    从第一个思路中可以看到：去掉一个元素后，不可能比之前的元素更长了。
//    我们可以直接跳到重复元素之后开始新的循环。
class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        start = maxLength = 0
        usedChar = {}
        for index, char in enumerate(s):
            if char in usedChar and start <= usedChar[char]:
                start = usedChar[char] + 1
            else:
                maxLength = max(maxLength, index - start + 1)
            usedChar[char] = index
        return maxLength


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int maxLen = 0;
        int lastRepeatPos = -1;
        for(int i=0; i<s.size(); i++){
            if (m.find(s[i])!=m.end() && lastRepeatPos < m[s[i]]) {
                lastRepeatPos = m[s[i]];
            }
            if ( i - lastRepeatPos > maxLen ){
            maxLen = i - lastRepeatPos;
            }
            m[s[i]] = i;
        }
        return maxLen;
    }
};


// 参考github上的图解：https://github.com/MisterBooo/LeetCodeAnimation
