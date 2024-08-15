class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int>mpp;
        for(auto it:s)
        {
            mpp[it]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mpp)
        {
            pq.push({it.second,it.first});
        }

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            while(it.first)
            {
                ans+=it.second;
                it.first--;
            }
        }

    return ans;
    }

};