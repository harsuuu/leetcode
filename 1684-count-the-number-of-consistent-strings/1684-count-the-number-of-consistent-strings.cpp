class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>st;
        for(auto it:allowed){
            st.insert(it);
        }   
        int cnt=0;
        for(int i=0;i<words.size();i++)
        {
            string s = words[i];
            int k=0;
            for(auto it:s)
            {
                if(st.find(it)==st.end())
                {
                    continue;
                }
                if(st.find(it)!=st.end())
                {
                    k++;
                }
            }
            if(k!=s.length()-1)
            {
                cnt++;
            }
        }
    return cnt;
    }
};