#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<char, int> keyboard = {
        {'q', 1},{ 'w', 1 },{ 'e', 1 },{ 'r', 1 },{ 't', 1 },{ 'y', 1 },{ 'u', 1 },{ 'i', 1 },{ 'o', 1 },{ 'p', 1 },
        { 'a', 2 },{ 's', 2 },{ 'd', 2 },{ 'f', 2 },{ 'g', 2 },{ 'h', 2 },{ 'j', 2 },{ 'k', 2 },{ 'l', 2 },
        { 'z', 3 },{ 'x', 3 },{ 'c', 3 },{ 'v', 3 },{ 'b', 3 },{ 'n', 3 },{ 'm', 3 }
    };
    bool isOneRow(string s) {
        int row = 0;
        for (int i = 0; i < s.length(); ++i) {
            int temp = keyboard[tolower(s[i])];
            if (row != 0 && temp != row) {
                return false;
            }
            row = temp;
        }
        return true;
    }
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        for (string s : words) {
            if (isOneRow(s)) {
                ans.push_back(s);
            }
        }
        return ans;
    }
};


int main()
{
    Solution s;
    vector<string> v{ "Hello", "Alaska", "Dad", "Peace" };

    for (string ans : s.findWords(v)) {
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}

