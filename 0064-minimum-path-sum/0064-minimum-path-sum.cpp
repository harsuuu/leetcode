class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j,vector<vector<int>>&dp)
    {
        //base case
        if(i==0 && j==0)    return grid[i][j];

        if(i<0 || j<0)      return INT_MAX;

        if(dp[i][j]!=-1)    return dp[i][j];

        //explore all posibilities
        int up = INT_MAX;
        if(i>0){
            up = grid[i][j] + solve(grid,i-1,j,dp);
        }
        int left = INT_MAX;
        if(j>0){
            left = grid[i][j] + solve(grid,i,j-1,dp);
        }
        //take out the mini
        return dp[i][j] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(grid,n-1,m-1,dp); 
    }
};