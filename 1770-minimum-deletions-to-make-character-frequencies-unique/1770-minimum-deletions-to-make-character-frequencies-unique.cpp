class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>count;    //key and value
        for(char c : s)
        count[c]++;    //frequency aa gyi.

        unordered_set<int>freqCount;
        int ans=0;
        for(auto &k : count)
        {
            int freq=k.second; //yani ye hai value
            while(freq>0  && freqCount.find(freq)!=freqCount.end())
            {
                freq--;
                ans++;
            }
            freqCount.insert(freq);
        }
        return ans;
    }
};