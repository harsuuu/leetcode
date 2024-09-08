class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end());
        vector<int>env; 
        for(int i=0;i<n;i++)
        {
            env.push_back(envelopes[i][1]);
        }
        int m = env.size();
        vector<int>temp;
        temp.push_back(env[0]);
        for(int i=1;i<m;i++)
        {
            if(env[i]>temp.back())
            {
                temp.push_back(env[i]);
            }
            else{
                int lb = lower_bound(temp.begin(),temp.end(),env[i])-temp.begin();
                temp[lb]=env[i];
            }
        }
    return temp.size();
    }
};