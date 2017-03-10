#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans_set;
        multimap<int, pair<int, int>> sum_map;

        if (nums.size() < 4) {
            return vector<vector<int>>();
        }

        // make pair sum map
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                sum_map.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));
            }
        }

        for (auto it = sum_map.begin(); it != sum_map.end(); ++it) {
            int value = target - it->first;
            auto ret = sum_map.equal_range(value);
            for (auto it2 = ret.first; it2 != ret.second; ++it2) {
                if (it->second.first != it2->second.first
                    && it->second.second != it2->second.second
                    && it->second.first != it2->second.second 
                    && it->second.second != it2->second.first) {
                    vector<int> tmp{ nums[it->second.first], nums[it->second.second], nums[it2->second.first], nums[it2->second.second] };
                    sort(tmp.begin(), tmp.end());
                    ans_set.insert(tmp);
                }
            }
        }

        vector<vector<int>> ans(ans_set.size());
        copy(ans_set.begin(), ans_set.end(), ans.begin());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{ 1, 0, -1, 0, -2, 2 };
    //vector<int> v{-3,-2,-1,0,0,1,2,3};

    for (vector<int> v : s.fourSum(v, 0)) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
