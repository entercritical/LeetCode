//
//  327_Count_of_Range_Sum.cpp
//  leetcode
//
//  Created by Suhwan Hwang on 2017. 1. 19..
//  Copyright © 2017년 Suhwan Hwang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    int lower;
    int upper;
    vector<long long> sums;
    
    int countRangeSumCross(int left, int right) {
        int mid = (left + right) / 2;
        int count = 0;
        int l = mid + 1;
        int u = mid + 1;
        for (int i = left; i <= mid; ++i) {
            while(l <= right && sums[l] - sums[i] < lower) l++;
            while(u <= right && sums[u] - sums[i] <= upper) u++;
            count += (u - l);
        }
        
        vector<long long> tmp;
        
        int i = left;
        int j = mid + 1;
        while (tmp.size() < right - left + 1) {
            if (i <= mid && (j > right || sums[i] < sums[j])) {
                tmp.push_back(sums[i++]);
            } else {
                tmp.push_back(sums[j++]);
            }
        }
        copy(tmp.begin(), tmp.end(), sums.begin() + left);
        
        return count;
    }
    
    int countRangeSumDnQ(int left, int right) {
        if (left == right) {
            return 0;
        }
        
        int mid = (left + right) / 2;
        int left_count = countRangeSumDnQ(left, mid);
        int right_count = countRangeSumDnQ(mid + 1, right);
        int cross_count = countRangeSumCross(left, right);
        
        return left_count + right_count + cross_count;
    }
    
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) {
            return 0;
        }
        
        this->lower = lower;
        this->upper = upper;
        sums.clear();
        sums.push_back(0);
        for (int i = 0;i < nums.size(); ++i) {
            sums.push_back(sums.back() + nums[i]);
        }
        
        return countRangeSumDnQ(0, (int)sums.size() - 1);
    }
};

int main(void)
{
    Solution s;
    vector<int> nums{-2, 5, -1};
    
    cout << s.countRangeSum(nums, -2, 2) << endl;
    return 0;
}
