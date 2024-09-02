class Solution {
public:
    int solve(string &s, string &t, int i , int j)
    {
        // base case
        if (j < 0) return 1; // If all characters of t are matched
        if (i < 0) return 0; // If s is exhausted and t is not

    
        //matching
        if(s[i]==t[j])
        {
            return solve(s,t,i-1,j-1) + solve(s,t,i-1,j);
        }
        //not matching
        return solve(s,t,i-1,j);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        return solve(s,t,n-1,m-1);
    }
};