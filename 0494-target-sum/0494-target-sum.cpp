class Solution {
public:
    int solve(int index, vector<int>&nums, int target)
    {
        if (index < 0) {
        // If we have reached the beginning of the list and the target is 0, 
        // we have found a valid way to sum to the target.
        return target == 0 ? 1 : 0;
    }
        //minus
        int minus = solve(index-1, nums,target-nums[index]);
 
        //plus
        int plus = solve(index-1,nums,target + nums[index]); 
       

    return minus + plus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(n-1,nums,target);
    }
};