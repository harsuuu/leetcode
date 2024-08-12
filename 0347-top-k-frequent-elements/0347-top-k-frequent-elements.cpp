class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        map<int,int>mpp;
        for(auto it:nums)
        {
            mpp[it]++;
        }
        int cnt=0;
        for(auto it:mpp)
        {
                ans.push_back(it.first);
                cnt++;
            
            if(cnt==k)  break;
        }
    return ans;
}
};