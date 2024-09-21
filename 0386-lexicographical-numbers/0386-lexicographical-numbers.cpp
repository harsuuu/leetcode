class Solution {
public:
    void solve(int curr, int n, vector<int>&ans){
        if(curr>n)     return;
        ans.push_back(curr);
        for(int appand=0;appand<=9;appand++)
        {
            int new_num = (curr*10)+appand;
            if(new_num>n){
                return;
            }
            solve(new_num,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int curr=1;curr<=9;curr++){
            solve(curr,n,ans);
        }
    return ans;
    }
};