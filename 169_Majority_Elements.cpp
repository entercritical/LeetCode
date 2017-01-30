//
//  169_Majority_Elements.cpp
//  leetcode
//
//  Created by Suhwan Hwang on 2017. 1. 30..
//  Copyright © 2017년 Suhwan Hwang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
    // O(n)
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int majority = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            if (count == 0) {
                count++;
                majority = nums[i];
            } else if (majority == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
        return majority;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums{1, 3, 2, 1, 1};
    
    cout << s.majorityElement(nums) << endl;
    return 0;
}
