class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];       //buy kr liya.
        int maxProfit = 0;
        for(int i=1;i<prices.size();i++)        //now sell krte check krna.
        {
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit,cost);
            mini = min(mini,prices[i]); 
        }
    return maxProfit;
    }
};