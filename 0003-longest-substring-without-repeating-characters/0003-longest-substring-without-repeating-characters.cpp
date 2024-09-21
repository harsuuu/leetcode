class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen=0;
        for(int i=0;i<n;i++)
        {
            set<char>st;
            for(int j=i;j<n;j++)
            {
                if(st.find(s[j])!=st.end())
                {
                    break;
                }
                maxLen = max(maxLen,j-i+1);
                st.insert(s[j]);
            }
        }
    return maxLen;
    }
};