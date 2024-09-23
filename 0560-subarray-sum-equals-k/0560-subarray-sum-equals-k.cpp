class Solution {
public:
    int subarraySum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        int sum=0;
        mpp[0]=1;   //I have seen 0 once. n 
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int curr = sum - goal;
            if(mpp.find(curr) != mpp.end())
            {
                cnt+=mpp[curr];
            }
            mpp[sum]++;
        }
    return cnt;
    }
};