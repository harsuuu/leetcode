class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int i = 0;
        for (auto it : spaces) {
            while (i < it) {
                ans += s[i];
                i++;
            }
            ans += ' ';
        }
        while (i < s.size()) {
            ans += s[i];
            i++;
        }
        return ans;
    }
};