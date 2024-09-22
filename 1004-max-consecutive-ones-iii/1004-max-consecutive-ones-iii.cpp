class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int length=0;
        int zero=0;
        int l=0,r=0;
        while(r<n)
        {
            if(nums[r]==0)  zero++;
            while(zero>k)
            {
                if(nums[l]==0)  zero--;
                l++;
            }
            if(zero<=k){
                length=r-l+1;
                maxLen=max(maxLen,length);
            }
            r++;
        }
    return maxLen;
    }
};