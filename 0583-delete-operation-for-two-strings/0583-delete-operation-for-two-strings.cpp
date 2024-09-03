class Solution {
public:
    int solve(string &text1, string &text2,int index1, int index2,vector<vector<int>>&dp)
    {
        if(index1 < 0 || index2 < 0)
        {
            return 0;
        }
        if(dp[index1][index2]!=-1)  return dp[index1][index2];
        //matching
        if(text1[index1]==text2[index2])
        {
            return dp[index1][index2] = 1 + solve(text1,text2,index1-1, index2-1,dp);
        }
        //not matching
        return dp[index1][index2] = 0 + max(solve(text1,text2,index1-1, index2,dp),solve(text1,text2,index1, index2-1,dp)); 
    }
    int minDistance(string word1, string word2) {
       
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        int lcsLength = solve(word1,word2,n-1,m-1,dp);

        // Minimum deletions needed
        return (n - lcsLength) + (m - lcsLength);
    }
};