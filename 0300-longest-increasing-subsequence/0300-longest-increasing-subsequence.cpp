class Solution {
public:
    int solve(vector<int>&nums,int i, int &prev,vector<vector<int>>&dp)
    {
        int n = nums.size();
        //base case 
        if(i==n)      return 0;

        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }    

        //not take
        int length = 0 + solve(nums,i+1,prev,dp);

        //take
        if(prev==-1 || nums[i]>nums[prev])
        {
            length = max(length, 1 + solve(nums,i+1,i,dp));
        }
        

        return dp[i][prev+1] = length;
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int n=nums.size();
         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(nums,0,prev,dp);
    }
};