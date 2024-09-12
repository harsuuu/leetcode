class Solution {
public:
    int solve(int ind, int buy, vector<int>&prices,int fee,vector<vector<int>>&dp)
    {
        int n = prices.size();
        //base case
        if(ind == n)      return 0;

        if(dp[ind][buy]!=-1)    return dp[ind][buy];

        //explore all posibilites
        int profit = 0;
        if(buy){
            int buy = -prices[ind] + solve(ind+1,0,prices,fee,dp); 
            int not_buy = 0 + solve(ind+1,1,prices,fee,dp);

            profit = max(buy,not_buy);
        }
        else{
            int sell = (prices[ind] - fee) + solve(ind+1,1,prices,fee,dp);
            int not_sell = 0 + solve(ind+1,0,prices,fee,dp);

            profit = max(sell,not_sell);
        }
    return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1)); 
        return solve(0,1,prices,fee,dp);
    }
};