#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> cache;
public:
    int numDecodingsSub(string& s, int start) {
        if (start == s.length()) {
            return 1;
        }

        if (s[start] == '0') {
            return 0;
        }

        if (cache[start] != -1) {
            return cache[start];
        }

        int count;
        count = numDecodingsSub(s, start + 1);

        if (start < s.length() - 1 &&
            (s[start] == '1' || (s[start] == '2' && s[start + 1] <= '6'))) {
            count += numDecodingsSub(s, start + 2);
        }
        cache[start] = count;
        return count;
    }

    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }

        cache.clear();
        cache.resize(s.length(), -1);
        return numDecodingsSub(s, 0);
    }
};


int main()
{
    Solution s;

    cout << s.numDecodings("123") << endl;

    return 0;
}
