//
//  338_Counting_Bits.cpp
//  leetcode
//
//  Created by Suhwan Hwang on 2016. 8. 16..
//  Copyright © 2016년 Suhwan Hwang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int count(int n) {
        int c = 0;
        while(n != 0) {
            if (n & 0x1) {
                c++;
            }
            n >>= 1;
        }
        return c;
    }
public:
    vector<int> countBits2(int num) {
        vector<int> result;
        
        for (int i = 0; i <= num; ++i) {
            result.push_back(count(i));
        }
        return result;
    }
    
    vector<int> countBits(int num) {
        vector<int> result;
        result.push_back(0);

        int s = 1;
        for (int i = 1; i <= num; ++i) {
            if (i >= s * 2) {
                s *= 2;
            }
            result.push_back(result[i - s] + 1);
        }
        
        return result;
    }
};

int main(void)
{
    Solution s;
    vector<int> v = s.countBits(32);
    for (int n : v) {
        cout << n << ", ";
    }
    cout << endl;
    return 0;
}
