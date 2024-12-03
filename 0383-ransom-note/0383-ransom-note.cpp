class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mpp1;
        unordered_map<char,int>mpp2;
        for(auto it:ransomNote)
        {
            mpp1[it]++;
        }
        for(auto it:magazine)
        {
            mpp2[it]++;
        }
        for(auto it:mpp1)
        {
            int a = it.first;
            int b = it.second;
            if(mpp2.find(a)!=mpp2.end())
            {
                if(mpp2[a]==b)
                {
                    return true;
                }
            }
        }
    return false;
    }
};