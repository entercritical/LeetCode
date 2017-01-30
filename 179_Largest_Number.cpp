//
//  179_Largest_Number.cpp
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
    static bool cmp(const string& a, const string& b) {
        return a + b > b + a;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str_nums;
        for (int n : nums) {
            str_nums.push_back(to_string(n));
        }
        
        sort(str_nums.begin(), str_nums.end(), cmp);
        
        string ans;
        for (string s : str_nums) {
            ans += s;
        }
        
        int i;
        for (i = 0; i < nums.size() - 1; ++i) {
            if (ans[i] != '0') {
                break;
            }
        }
        return ans.substr(i);
    }
};

int main(void)
{
    Solution s;
    vector<int> nums{3, 30, 34, 5, 9};
    //vector<int> nums{0, 0, 0};
    
    cout << s.largestNumber(nums) << endl;
    return 0;
}
