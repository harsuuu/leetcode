class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int res=1;
            for(int j=0;j<n;j++)
            {
                if(j!=i)
                {
                    res*=nums[j];
                }
            }
            ans.push_back(res);
        }
    return ans;
    }
};