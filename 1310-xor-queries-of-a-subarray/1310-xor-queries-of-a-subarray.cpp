class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto it:queries)
        {
            int temp1=it[0];
            int temp2=it[1];

            int temp = arr[temp1];
            for(int i=temp1+1;i<=temp2;i++)
            {   
                temp^=arr[i];
            }
            ans.push_back(temp);
        }
    return ans;
    }
};