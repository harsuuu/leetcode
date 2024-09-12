class Solution {
public:
    int solve(vector<int>&prices,int ind,int buy)
    {
        int n=prices.size();
        if(ind>=n)  return 0;

        int profit=0;
        if(buy)
        {
            int buyProfit = -prices[ind] + solve(prices,ind+1,0);
            int skipPro = 0 + solve(prices,ind+1,1);

            profit=max(buyProfit,skipPro);
        }
        else{
            int sellProfit = prices[ind] + solve(prices,ind+1,1);
            int skipSell = 0 + solve(prices,ind+1,0);

            profit=max(sellProfit,skipSell);
        }

    return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices,0,true);
    }
};