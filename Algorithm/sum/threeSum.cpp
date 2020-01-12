// 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

// 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
        int value = 0; // 三数之和的值

        // 先排序数组，并check边界条件
        sort(nums.begin(), nums.end());
        if (nums.size() < 3 || nums[0] > value || nums[nums.size()-1] < value)
            return result;


        for (int i=0; i < nums.size()-2; i++) {
            if (i>0 && num[i] == num[i-1])
                continue;
            
            int j = i+1;
            int k = num.size()-1;

            while(j < k) {
                value = num[i] + num[j] + num[k];

                if (value == 0) {
                    result.push_back({num[i], num[j], num[k]});
                    j++;
                    // 这个是判断重复的情况
                    while (j < num.size() && num[j] == num[j - 1])
                        j++;

                    k--;
                    while (k >= 0 && num[k] == num[k + 1])
                        k--;
                } else if (value > 0) 
                    k--;
                else
                    j++;
            }
        }

        return result;
    }
};


// 源码分析
// S = {-1 0 1 2 -1 -4}
// 排序后：
// S = {-4 -1 -1 0 1 2}
//       ↑  ↑        ↑
//       i  j        k
//          →        ←
// i每轮只走一步，j和k根据S[i]+S[j]+S[k]=ans和0的关系进行移动，且j只向后走（即S[j]只增大），k只向前走（即S[k]只减小）
// 如果ans>0说明S[k]过大，k向前移；如果ans<0说明S[j]过小，j向后移；ans==0即为所求。
// 至于如何取到所有解，看代码即可理解，不再赘述。





