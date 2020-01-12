    class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> result;
            // 异常判断
            if (nums.size() < 4) 
                return result;

            sort(nums.begin(), nums.end());

            unordered_map<int, vector<pair<int, int> > > cache;

            for (size_t a = 0; a < nums.size(); ++a) {
                for (size_t b = a + 1; b < nums.size(); ++b) {
                    cache[nums[a] + nums[b]].push_back(pair<int, int>(a, b));
                }
            }

            for (int c = 0; c < nums.size(); ++c) {
                for (size_t d = c + 1; d < nums.size(); ++d) {
                    const int key = target - nums[c] - nums[d];
                    if (cache.find(key) == cache.end()) 
                        continue;
                    
                    const auto& vec = cache[key];
                    for (size_t k = 0; k < vec.size(); ++k) {
                        if (c <= vec[k].second)
                            continue; // 有重叠
                        result.push_back( { nums[vec[k].first], nums[vec[k].second], nums[c], nums[d] });
                    }
                }
            }

            sort(result.begin(), result.end());
            result.erase(unique(result.begin(), result.end()), result.end());

            return result;

        }
    };

    // 这里用了很多c++的STL容器的操作
    // vector（sort、begin、end、erase）、pair、unordered_map（push_back、find()、end()、auto）

