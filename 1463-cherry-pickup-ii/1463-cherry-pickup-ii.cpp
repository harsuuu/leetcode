class Solution {
public:
    int solve(vector<vector<int>>& grid,int i, int j1, int j2,vector<vector<vector<int>>>&dp)
    {
        int n = grid.size();
        int m = grid[0].size(); 
        //base case
        if(j1<0 || j1>=m || j2<0 || j2>=m)      return -1e8;
        if(i==n-1)
        {
            if(j1==j2)  return grid[i][j1];
            else        return grid[i][j1]+grid[i][j2];
        }

        if(dp[i][j1][j2]!=-1)       return dp[i][j1][j2];

        //explore all the path
        int maxi = -1e8;
        for(int dj1=-1;dj1<=+1;dj1++){
            for(int dj2=-1;dj2<=+1;dj2++){
                int val=0;
                if(j1==j2)   val = grid[i][j1];
                else         val = grid[i][j1] + grid[i][j2];
                val += solve(grid,i+1,j1+dj1,j2+dj2,dp);
                // if(j1==j2){
                //     maxi = max(maxi, grid[i][j1] + solve(grid,i+1,j1+dj1,j2+dj2));
                // }
                // else{
                //     maxi=max(maxi,grid[i][j1]+grid[i][j2]+solve(grid,i+1,j1+dj1,j2+dj2));
                // }
                maxi=max(maxi,val);
            }
        } 
    return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(grid,0,0,m-1,dp);
    }
};