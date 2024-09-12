class Solution {
public:
    int solve(int ind, int buy, vector<int>&prices, int k, vector<vector<vector<int>>>&dp)
    {
        int n = prices.size();
        //base case
        if(k==0)    return 0;
        if(ind==n)    return 0;

        if(dp[ind][buy][k]!=-1)         return dp[ind][buy][k];

        //explore all posivilities
        int profit=0;
        if(buy)
        {
            int buy = -prices[ind] + solve(ind+1,0,prices,k,dp);
            int not_buy = 0 + solve(ind+1,1,prices,k,dp);

            profit = max(buy,not_buy);
        }
        else{
            int sell = prices[ind] + solve(ind+1,1,prices,k-1,dp);
            int not_sell = 0 + solve(ind+1,0,prices,k,dp);

            profit = max(sell,not_sell);
        }
    return dp[ind][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); 
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,prices,k,dp);
    }
};