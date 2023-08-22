class Solution {
    public:
    void permutation(vector<int>nums,int i,vector<vector<int>>&ans)
    {
        if(i>=nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            permutation(nums,i+1,ans);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int i=0;
        permutation(nums,i,ans);

        return ans;
    }
};
