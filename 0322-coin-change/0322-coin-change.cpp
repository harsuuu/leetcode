class Solution {
public:
    int solve(int index, vector<int>&coins, int target,vector<vector<int>>&dp)
    {
        //base case
        if(index == 0){
            // Check if the target sum is divisible by the first element
            if(target % coins[0] == 0)
                return target / coins[0]; // If yes, return the quotient as the answer
            else
                return 1e9; // Otherwise, return a very large value to indicate it's not possible
        }

        if(dp[index][target]!=-1)       return dp[index][target];
        // if(index==0)
        // {
        //     if(coins[index]>target)             return INT_MAX;
        //     else if(coins[index]==target)       return 1;
        //     else if(target%coins[index]==0)     return target/coins[index];
        //     else                                return INT_MAX;
        // }

        //not pick
        int not_take = 0 + solve(index-1,coins,target,dp);

        //take
        int take = INT_MAX;
        if(coins[index]<=target)
        {
            take = 1 + solve(index, coins, target-coins[index],dp);
        }
    
    return dp[index][target]= min(not_take,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = solve(n-1,coins,amount,dp);
        
        if(ans==1e9)
        {
            return -1;
        }
    return ans;
    }
};