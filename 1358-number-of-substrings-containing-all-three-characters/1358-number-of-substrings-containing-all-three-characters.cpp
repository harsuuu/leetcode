class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            set<char>st;
            for(int j=i;j<n;j++)
            {
                st.insert(s[j]);
                if (st.size() == 3) {  // Check for exactly 3 distinct characters
                    cnt++;  // Valid substring found
                }
            }
            if (st.size() > 3) {  
                break;
            }
        }
    return cnt;
    }
};