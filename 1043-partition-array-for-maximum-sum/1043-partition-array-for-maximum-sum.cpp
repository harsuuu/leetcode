class Solution {
public:
    int solve(vector<int>&arr, int k, int ind,vector<int>&dp)
    {
        int n = arr.size();
        if(ind==n)          return 0;

        if(dp[ind]!=-1)     return dp[ind];

        int maxAns = INT_MIN;
        int len = 0;
        int maxi =  INT_MIN; 
        for(int j=ind;j<min(n,ind+k);j++)
        {
            len++;
            maxi=max(maxi,arr[j]);
            int cost = len*maxi + solve(arr,k,j+1,dp);

            maxAns = max(cost,maxAns);
        }
    return dp[ind] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size(); 
        vector<int>dp(n,-1);
        return solve(arr,k,0,dp);
    }
};