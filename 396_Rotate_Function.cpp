//
//  396_Rotate_Function.cpp
//  leetcode
//
//  Created by Suhwan Hwang on 2016. 10. 16..
//  Copyright © 2016년 Suhwan Hwang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) {
            return 0;
        }
        
        int sum = accumulate(A.begin(), A.end(), 0);
        int before = 0;
        for (int i = 0; i < A.size(); ++i) {
            before += i * A[i];
        }
        
        int max_value = before;
        for (int i = A.size() - 1; i > 0; --i) {
            before += sum - A.size() * A[i];
            max_value = max(max_value, before);
        }
        return max_value;
    }
};

int main(void)
{
    Solution s;
    
    vector<int> a{4, 3, 2, 6};
    cout << s.maxRotateFunction(a) << endl;
    
    return 0;
}