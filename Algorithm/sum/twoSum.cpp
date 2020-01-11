// 对C++ STL容器来说，也只是入门
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hmap;
        vector<int> result;
        int numFind;
        for (int i=0; i<nums.size(); i++) {
            numsFind = target - nums[i];

            // if numFind id found in hashmap, return them
            if (hmap.find(numsFind) != hmap.end()) {
                result.push_back(hmap[numsFind]);
                result.push_back(i);    
                
                return result;
            }

            // numbers was not found, put it in the map
            hmap[nums[i]] = i;
        }
        
        return result;
    }

};