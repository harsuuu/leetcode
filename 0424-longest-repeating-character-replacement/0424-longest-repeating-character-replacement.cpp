class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), maxl = 0, ans = 0;
        int l = 0, r = 0; 
        unordered_map<char , int> count;

        while (r < n) {
        count[s[r]]++;
        maxl = max(maxl, count[s[r]]);

        // Adjust the window size if the number of replacements exceeds 'k'
        while ((r - l + 1) - maxl > k) {
            count[s[l]]--;
            l++;
        }

        // Update the answer to the maximum window size found
        if((r-l+1)-maxl<=k){
            ans = max(ans, r - l + 1);
        }
        
        r++;
    }

    return ans;
    }
};