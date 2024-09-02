class Solution {
public:
    int solve(string &s, string &t, int i , int j, vector<vector<int>>&dp)
    {
        // base case
        if (j == 0) return 1; // If all characters of t are matched
        if (i == 0) return 0; // If s is exhausted and t is not
     
        if(dp[i][j]!=-1)    return dp[i][j];
    
        //matching
        if(s[i-1]==t[j-1])
        {
            return dp[i][j] = solve(s,t,i-1,j-1,dp) + solve(s,t,i-1,j,dp);
        }
        //not matching
        return dp[i][j] = solve(s,t,i-1,j,dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s,t,n,m,dp);
    }
};