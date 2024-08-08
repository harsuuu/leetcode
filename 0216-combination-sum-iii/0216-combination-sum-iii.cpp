class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&v,int n,int k,int sum,int index)
    {
        if(k==0 && sum==n)
        {
            ans.push_back(v);
            return;
        }
        if (sum > n || k < 0) {
        return;
        }

        for(int i=index;i<=9;i++)
        {
            v.push_back(i);
            solve(ans,v,n,k-1,sum+i,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(ans,v,n,k,0,1);
    
    return ans;
    }
};