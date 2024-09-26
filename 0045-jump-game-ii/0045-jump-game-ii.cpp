class Solution {
public:
    int solve(int i, vector<int>& nums, int n,vector<int>&dp) {
    
    if (i >= n - 1) return 0;

    if(dp[i]!=-1)   return dp[i];

    int mini = INT_MAX;
    // Explore all possible jumps from the current index
    for (int j = 1; j <= nums[i]; j++) {
            int result = solve(i + j, nums, n,dp);
            if (result != INT_MAX) {
                mini = min(mini, 1 + result);  // Only add 1 if result is not INT_MAX
            }
    }
    return dp[i] = mini;
}
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,n,dp);
    }
};