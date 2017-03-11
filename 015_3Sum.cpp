#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        if (nums.size() < 3) {
            return ans;
        }

        sort(nums.begin(), nums.end()); // sorting

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                // skip same number
                continue;
            }

            int target = -nums[i];
            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high) {
                int sum = nums[low] + nums[high];
                if (sum == target) {
                    ans.push_back(vector<int>{nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                    // skip same number
                    while (nums[low - 1] == nums[low]) low++;
                    while (nums[high + 1] == nums[high]) high--;
                } else if (sum > target) {
                    high--; // decrease sum
                } else {
                    low++; // increase sum
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{ -1, 0, 1, 2, -1, -4 };
    for (vector<int>a : s.threeSum(v)) {
        for (int n : a) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}

