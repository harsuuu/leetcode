class Solution {
public:
    string compressedString(string word) {
        string ans;
        int n = word.size();
        int i = 0;

        while (i < n) {
            char c = word[i];
            int count = 0;
            while (i < n && word[i] == c && count < 9) {
                count++;
                i++;
            }
            ans += to_string(count) + c;
        }

    return ans;
    }
};