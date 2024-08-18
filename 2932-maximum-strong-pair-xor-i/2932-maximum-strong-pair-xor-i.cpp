class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int x=0;x<nums.size();x++)
        {
            for(int y=x;y<nums.size();y++)
            {
                if(abs(nums[x]-nums[y]) <= min(nums[x],nums[y]))
                {
                    maxi=max(maxi,nums[x]^nums[y]);
                }
            }
        }
    return maxi;
    }
};