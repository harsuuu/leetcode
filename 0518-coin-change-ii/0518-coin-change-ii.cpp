class Solution {
public:
    int solve(int index, vector<int>&coins, int target,vector<vector<int>>&dp)
    {
        //base case
        if(index==0)
        {
            if(target % coins[index]==0)      return 1;
            //else if(target==0)                return 0;  --> ye sb (target==0) else m aa jayega.
            else                              return 0;                          
        }

        if(dp[index][target]!=-1)   return dp[index][target];

        //not take 
        int not_take = solve(index-1,coins,target,dp);
        //take
        int take=0;
        if(coins[index]<=target)
        {
            take = solve(index,coins,target-coins[index],dp);
        }

    return dp[index][target] = take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(n-1,coins,amount,dp);
    }
};