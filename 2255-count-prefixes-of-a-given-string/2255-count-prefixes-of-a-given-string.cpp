class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt=0;
        for (auto it:words) { // Iterate through the words
            if (s.find(it)==0) {    // Check if 'it' is a prefix of 's'
                cnt++;
            }
        }
    return cnt;
    }
};