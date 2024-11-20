class Solution {
public:
    int find(int n,vector<int>&dp)
    {
        if(n==0)            return 0;
        if(n==1 || n==2)    return 1;

        //step 3 : check answer is already exits or not.
        if(dp[n]!=-1)   return dp[n];

        //Step 2 : Store answer in dp array
        dp[n] = find(n-1,dp) + find(n-2,dp) + find(n-3,dp);

        return dp[n]; 
    }
    int tribonacci(int n) {
        //step 1 : Create dp array
        vector<int>dp(n+1,-1);
        return find(n,dp);
    }
};