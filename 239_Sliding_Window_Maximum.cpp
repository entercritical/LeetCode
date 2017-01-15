//
//  239_Sliding_Window_Maximum.cpp
//  leetcode
//
//  Created by Suhwan Hwang on 2016. 12. 14..
//  Copyright © 2016년 Suhwan Hwang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct RMQ {
    int n;
    vector<int> rangeMax;
    RMQ(const vector<int>& array) {
        n = (int)array.size();
        rangeMax.resize(n * 4);
        init(array, 0, n - 1, 1);
    }
    
    int init(const vector<int>& array, int left, int right, int node) {
        if (left == right) {
            return rangeMax[node] = array[left];
        }
        
        int mid = (left + right) / 2;
        int leftMax = init(array, left, mid, node * 2);
        int rightMax = init(array, mid + 1, right, node * 2 + 1);
        return rangeMax[node] = max(leftMax, rightMax);
    }
    
    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (right < nodeLeft || nodeRight < left)
            return numeric_limits<int>::min();
        if (left <= nodeLeft && nodeRight <= right)
            return rangeMax[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return max(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }
    
    int query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }
};

class Solution {
    
public:
    vector<int> maxSlidingWindowBF(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.empty()) {
            return result;
        }
        
        for (int i = 0; i <= nums.size() - k; ++i) {
            int value = numeric_limits<int>::min();
            for (int j = i; j < i + k; ++j) {
                value = max(value, nums[j]);
            }
            result.push_back(value);
        }
        return result;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) {
            return vector<int>();
        }
        
        RMQ rmq(nums);
        vector<int> result;
        
        for (int i = 0; i <= nums.size() - k; ++i) {
            result.push_back(rmq.query(i, i + k - 1));
        }
        return result;
    }
};

int main(void) {
    Solution s;
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    
    vector<int> result = s.maxSlidingWindow(nums, 3);
    for (int n : result) {
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}
