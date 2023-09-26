class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int i=0;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for( i=0;i<nums.size();i++)
    {
        if(nums[i]!=i)
            return i;
    }

return n;

        
    }
};