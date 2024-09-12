class Solution {
public:
    int solve(int index, int buy, vector<int>&prices, int cap,vector<vector<vector<int>>>&dp)
    {
        int n = prices.size();  
        //base case
        if(cap==0)      return 0;
        if(index==n)    return 0;

        if(dp[index][buy][cap]!=-1)     return dp[index][buy][cap];

        //explore all posibilities
        int profit = 0;
        if(buy)
        {
            int buy = -prices[index] + solve(index+1,0, prices,cap,dp);
            int not_buy = 0 + solve(index+1,1,prices,cap,dp);

            profit = max(buy,not_buy);
        }
        else{
            int sell = prices[index] + solve(index+1,1,prices,cap-1,dp);
            int not_sell = 0 + solve(index+1,0,prices,cap,dp);

            profit = max(sell,not_sell);
        }
    return dp[index][buy][cap] =  profit;
    }
    int maxProfit(vector<int>& prices) {
        //1 --> can buy
        //0 --> can not buy only sell
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,prices,2,dp);
    }
};