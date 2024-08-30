class Solution {
public:
    bool allZero(const unordered_map<char, int>& mpp) {
    for (const auto& it : mpp) {
        if (it.second > 0) {
            return false;
        }
    }
    return true;
    }
    vector<int> findAnagrams(string txt, string pat) {
        vector<int>ans;
         unordered_map<char,int>mpp;
        for(auto it:pat)
        {
            mpp[it]++;
        }
        
        int i=0,j=0;
       
        int k = pat.size();
        int n = txt.size();
        while(j<n)
        {
            mpp[txt[j]]--;
            if(j-i+1==k)
            {
                if(allZero(mpp))
                {
                    ans.push_back(i);
                }
                
                mpp[txt[i]]++;
                i++;
            }
            j++;
        }
    return ans;
    }
};