#include <map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        multimap<int, int> nums_map;
        
        for (int i = 0; i < nums.size(); ++i) {
            nums_map.insert(make_pair(nums[i], i));        
        }
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            auto search = nums_map.equal_range(target - nums[i]);
            
            for (auto it = search.first; it != search.second; ++it) {
                if (it->second != i) {
                    solution.push_back(i);
                    solution.push_back(it->second);
                    return solution;
                }
            }
        }
        
        return solution;
    }
};
