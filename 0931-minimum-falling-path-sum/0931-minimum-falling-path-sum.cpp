class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j,vector<vector<int>>&dp)
    {
        int m = matrix[0].size();
        //base case
        if(i==0)    return matrix[i][j];
        if(j < 0 || j >= m) {
            return 1e9 + 7;
        }

        if(dp[i][j]!=-1)    return dp[i][j];

        int up = INT_MAX, up_left = INT_MAX, up_right = INT_MAX;
    
        // Explore paths
        if (i > 0) {
            up = matrix[i][j] + solve(matrix, i - 1, j, dp);
        }
        if (i > 0 && j > 0) {
            up_left = matrix[i][j] + solve(matrix, i - 1, j - 1, dp);
        }
        if (i > 0 && j < m - 1) {
            up_right = matrix[i][j] + solve(matrix, i - 1, j + 1, dp);
        }
    
        //return mini
        return dp[i][j] = min(up,min(up_left,up_right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int mini = 1e9+7;
        for(int j=0;j<m;j++)
        {
            mini=min(mini,solve(matrix,n-1,j,dp));
        }
    return mini;
    }
};