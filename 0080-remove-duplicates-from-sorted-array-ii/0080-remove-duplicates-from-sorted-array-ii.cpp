class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it:nums)
        {
            mpp[it]++;
        }
        int k=0;
        for(auto it:nums)
        {
            if(mpp[it]>0)
            {
                int mini = min(mpp[it],2);
                for(int i=0;i<mini;i++)
                {
                    nums[k]=it;
                    k++;
                }
                mpp[it]=0;
            }
        }
    return k;
    }
};