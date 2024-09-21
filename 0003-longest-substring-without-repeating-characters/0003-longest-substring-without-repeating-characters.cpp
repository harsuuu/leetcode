class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l=0,r=0;
        int maxLen=0;
        unordered_map<char,int>mpp;
        while(r<n)
        {
            if(mpp.find(s[r])!=mpp.end() && mpp[s[r]] >= l)
            {
                l=mpp[s[r]]+1;
            }
            mpp[s[r]]=r;
            maxLen = max(maxLen,r-l+1);
            r++;
        }
    return maxLen;
    }
};