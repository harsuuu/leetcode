class Solution {
public:
    bool solve(vector<int>&nums,int index,int target,vector<vector<int>>&dp)
    {
        if(target==0)       return true;

        if(index==0)
        {
            return (nums[index]==target);
        }

        if(dp[index][target]!=-1)   
        {
            return dp[index][target];
        }
        //not take
        bool not_take = solve(nums,index-1,target,dp);
       
        bool take = false;

        if(nums[index]<=target)
        {
            take = solve(nums,index-1,target-nums[index],dp);
        }

    return dp[index][target]=(take || not_take);
    }
    bool canPartition(vector<int>& nums) {
        
        int total_sum = 0;
        for(auto it:nums)
        {
            total_sum+=it;
        }  
        
        if(total_sum %2!=0)
        {
            return false;
        }
    int n = nums.size();
    int target = total_sum/2;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return solve(nums,n-1,target,dp); 
    }
};