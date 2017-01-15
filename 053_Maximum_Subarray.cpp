//
//  053_Maximum_Subarray.cpp
//  leetcode
//
//  Created by Suhwan Hwang on 2017. 1. 14..
//  Copyright © 2017년 Suhwan Hwang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class SolutionDivideAndConquer {
public:
    int findCrossMaxSubarray(vector<int>& nums, int left, int right) {
        int mid = (left + right) / 2;
        int left_max = INT_MIN;
        int sum = 0;
        
        for (int i = mid; i >= left; --i) {
            sum += nums[i];
            
            if (sum > left_max) {
                left_max = sum;
            }
        }
        
        int right_max = INT_MIN;
        sum = 0;
        
        for (int i = mid + 1; i <= right; ++i) {
            sum += nums[i];
            
            if (sum > right_max) {
                right_max = sum;
            }
        }
        
        return max(max(left_max, right_max), left_max + right_max);
    }
    
    int findMaxSubarray(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        
        int mid = (left + right) / 2;
        int left_max = findMaxSubarray(nums, left, mid);
        int right_max = findMaxSubarray(nums, mid + 1, right);
        int cross_max = findCrossMaxSubarray(nums, left, right);
        
        return max(max(left_max, right_max), cross_max);
    }
    
    int maxSubArray(vector<int>& nums) {
        return findMaxSubarray(nums, 0, (int)nums.size() - 1);
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            
            if (sum > max_sum) {
                max_sum = sum;
            }
            
            if (sum < 0) {
                sum = 0;
            }
        }
        return max_sum;
    }
};

int main(void)
{
    Solution s;
    vector<int> my_array{-2,1,-3,4,-1,2,1,-5,4};
    
    cout << s.maxSubArray(my_array) << endl;
    return 0;
}
