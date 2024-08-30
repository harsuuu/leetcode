class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())      return false;
        unordered_map<char,int>mpp;
        for(auto it:s)
        {
            mpp[it]++;
        }
        // Subtract counts based on the second string
        for (auto it : t) {
            if (mpp.find(it) != mpp.end() && mpp[it] > 0)
            {
                mpp[it]--;
            }
            else {
                return false; // Character not found or count is zero, not an anagram
            }
        }
    return true;
    }
};