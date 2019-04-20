class Solution {
    public:
        int removeElement(int A[], int n, int elem) {
            int i = 0;
            int j = 0;
            for (i=0; i<n; i++) {
                if (A[i] == elem) {
                    continue;
                }

                A[j] = A[i];
                j++;
            }

            return j;
        }
};

//想法挺不错的
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int i = 0;
//         int j = 0;
        
//         for (i; i<nums.size(); i++) {
            
//             if (nums[i] == val)
//                 continue;
            
//             nums[j]=nums[i];
//             j++;
            
//         }
        
//         return j;
//     }
// };