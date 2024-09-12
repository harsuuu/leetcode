class Solution {
public:
    int solve(int ind, int buy, vector<int>&prices,vector<vector<int>>&dp)
    {
        int n = prices.size();
        //base case
        if(ind>=n)        return 0;         //qki --> ind+2 ja rhe uske hisab se base case

        if(dp[ind][buy]!=-1)    return dp[ind][buy];

        //explore
        int profit=0;
        if(buy)
        {
            int buy_stock = -prices[ind] + solve(ind+1,0,prices,dp);
            int not_buy = 0 + solve(ind+1,1,prices,dp);

            profit = max(buy_stock,not_buy);
        }
        else{
            //if ind==n-1 to base case hit ho jayega.
            int sell = prices[ind] + solve(ind+2,1,prices,dp);
            int not_sell = 0 + solve(ind+1,0,prices,dp);

            profit = max(sell,not_sell);
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};