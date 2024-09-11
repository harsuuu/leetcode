class Solution {
public:
    int solve(int i, int j, vector<int>&cuts,vector<vector<int>>&dp)
    {
        if(i>j)     return 0;

        if(dp[i][j]!=-1)    return dp[i][j];

        int mini = 1e9;
        for(int index=i;index<=j;index++)
        {   
            int total = (cuts[j+1] - cuts[i-1]) + solve(i,index-1,cuts,dp) + solve(index+1,j,cuts,dp);

            mini=min(mini,total);
        }
    return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);

        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
    return solve(1,c,cuts,dp);
    }
};