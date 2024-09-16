class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size(); 
        vector<int>dp(n+1,0);
        dp[n]=0;
        for(int ind = n-1;ind>=0;ind--)
        {
            int maxAns = INT_MIN;
            int len = 0;
            int maxi =  INT_MIN; 
            for(int j=ind;j<min(n,ind+k);j++)
            {
                len++;
                maxi=max(maxi,arr[j]);
                int cost = len*maxi + dp[j+1];

                maxAns = max(cost,maxAns);
            }
        dp[ind] = maxAns;
        }
    return dp[0];
    }
};