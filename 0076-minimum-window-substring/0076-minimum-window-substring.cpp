class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(),m = t.length();
        int mini = INT_MAX;
        int sInd = -1;
        int l=0,r=0,cnt=0;
        unordered_map<char, int> mpp;   
        for (auto it : t) {
                mpp[it]++;
        }          
        while (r < n) {
            if (mpp[s[r]] > 0) {
                cnt++;
            }
    
            mpp[s[r]]--;
            r++;
    
            while (cnt == m) {
                // Update the minimum length window if a smaller one is found
                if (r - l < mini) {
                    mini = r - l;
                    sInd = l;
                }
                mpp[s[l]]++;
                // If the character being removed is required in t, decrease the match count
                if (mpp[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
    }
    if(sInd == -1) return "";

    return s.substr(sInd, mini);
    }
};