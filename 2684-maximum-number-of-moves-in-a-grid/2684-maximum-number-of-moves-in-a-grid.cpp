class Solution {
public:
    int n, m;

    int solve(int row, int col, vector<vector<int>>& grid,vector<vector<int>>&dp) {
        if (row < 0 || row >= n || col >= m) return 0; 
        
        if(dp[row][col]!=-1)    return dp[row][col];

        int maxMoves = 0;
        // Right
        if (col + 1 < m && grid[row][col] < grid[row][col + 1]) {
            maxMoves = max(maxMoves, 1 + solve(row, col + 1, grid,dp));
        }
        // Right-upper diagonal
        if (row - 1 >= 0 && col + 1 < m && grid[row][col] < grid[row - 1][col + 1]) {
            maxMoves = max(maxMoves, 1 + solve(row - 1, col + 1, grid,dp));
        }
        // Right-lower diagonal
        if (row + 1 < n && col + 1 < m && grid[row][col] < grid[row + 1][col + 1]) {
            maxMoves = max(maxMoves, 1 + solve(row + 1, col + 1, grid,dp));
        }

        return dp[row][col] = maxMoves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxTotalMoves = 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    
        for (int i = 0; i < n; i++) {
            maxTotalMoves = max(maxTotalMoves, solve(i, 0, grid,dp));
        }

    return maxTotalMoves;
    }
};