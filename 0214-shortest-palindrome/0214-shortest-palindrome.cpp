class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        string rev = s;
        reverse(rev.begin(),rev.end());
        for(int i=0;i<n;i++)
        {
            //if not equal to kuch nhi krna khud continue ho jayega.
            if(memcmp(s.c_str(), rev.c_str() + i, n - i) == 0)
            {
                return rev.substr(0,i)+s;
            }
        } 
    return rev+s;
    }
};