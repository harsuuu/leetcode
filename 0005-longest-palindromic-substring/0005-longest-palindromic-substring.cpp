class Solution {
public:
    bool checkPaline(string s, int i, int j)
    {
        if(i>=j)    return true;

        if(s[i]==s[j])
        {
            return checkPaline(s,i+1,j-1);
        }
    return false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        
        int sp = -1;
        int maxLength = INT_MIN;

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(checkPaline(s,i,j)==true)
                {
                    if(j-i+1 > maxLength)
                    {
                        maxLength = j-i+1;
                        sp=i;
                    }
                }
            }
        }
    return s.substr(sp,maxLength);
    }
};