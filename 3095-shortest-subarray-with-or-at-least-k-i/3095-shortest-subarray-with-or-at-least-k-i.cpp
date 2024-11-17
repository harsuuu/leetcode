class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int len = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int xr=0;
            for(int j=i;j<n;j++)
            {
                xr|=nums[j];
                if(xr>=k)
                {
                    len = min(len,j-i+1);
                    break;
                }
            }
        }
    return (len == INT_MAX)?-1:len;
    }
};