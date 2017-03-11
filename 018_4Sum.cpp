#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum_using_map(vector<int>& nums, int target) {
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
    
    // https://en.wikipedia.org/wiki/3SUM
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end()); // sorting
        for (int first = 0; first < nums.size() - 3; ++first) {
            if (first > 0 && nums[first - 1] == nums[first]) {
				// skip same number
                continue;
            }
            for (int second = first + 1; second < nums.size() - 2; ++second) {
                if (second > first + 1 && nums[second - 1] == nums[second]) {
					// skip same number
                    continue;
                }
                int t = target - (nums[first] + nums[second]);
                int low = second + 1;
                int high = nums.size() - 1;
                while (low < high) {
                    int sum = nums[low] + nums[high];
                    if (sum == t) {
                        ans.push_back(vector<int>{nums[first], nums[second], nums[low], nums[high]});
                        low++;
                        high--;
                        // skip same number
                        while (nums[low - 1] == nums[low]) low++;
                        while (nums[high + 1] == nums[high]) high--;
                    } else if (sum > t) {
                        high--; // decrease sum
                    } else {
                        low++; // increase sum
                    }
                }
            }
        }
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
