class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp1(n,1);
        vector<int>dp2(n,1);
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i])
                {
                    dp1[i]=max(dp1[i],1+dp1[prev]);
                }
            }
        }
        reverse(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i])
                {
                    dp2[i]=max(dp2[i],1+dp2[prev]);
                }
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if(dp1[i]==1 || dp2[i]==1)
            {
                continue;
            }
            else{
                maxi=max(maxi,dp1[i]+dp2[i]-1);
            }
        }

    return nums.size()-maxi;
    }
};