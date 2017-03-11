#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<char, int> keyboard;
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
    Solution() {
        vector<string> k{ "qwertyuiop", "asdfghjkl", "zxcvbnm" };
        for (int row = 0; row < k.size(); ++row) {
            for (int i = 0; i < k[row].length(); ++i) {
                keyboard.insert(make_pair(k[row][i], row + 1));
            }
        }
    }
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

