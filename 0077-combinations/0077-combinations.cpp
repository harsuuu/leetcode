class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&v,int n,int k, int index)
    {
        if(k==0)
        {
           ans.push_back(v);
            return;
        }
        if(k<0)    return;

        for(int i=index;i<=n;i++)
        {
            v.push_back(i);
            solve(ans,v,n,k-1,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(ans,v,n,k,1);

    return ans;
    }
};