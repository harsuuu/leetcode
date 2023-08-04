class Solution {
public:
    int topDownSolve(int n,vector<int>&dp)
    {
        //base case
        if(n==0 || n==1)
        {
            return n;
        }
        //step 3: check answer aaya h ki nhi agr -1 hi hai mtlb abhi answer nhi aaya hai.
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        //step 2 : hm yha krte the f(n)=f(n-1)+f(n-2) and then f(n) return kr dete the ab kya krenge f(n) means answer ko dp se replace kr denge.
        dp[n]=topDownSolve(n-1,dp)+topDownSolve(n-2,dp);
        return dp[n];
    }

    int fib(int n) {
     //step 1: create dp array
     vector<int>dp(n+1,-1);
     int ans = topDownSolve(n,dp);
     return ans;
    }

};