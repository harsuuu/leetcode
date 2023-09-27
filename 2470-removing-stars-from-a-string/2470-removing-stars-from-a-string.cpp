class Solution {
public:
    string removeStars(string s) {
      vector<char>c;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]!='*')
            {
                c.push_back(s[i]);
            }
            else
            {
                c.pop_back();
        }
        }
        string ans="";
        for(auto it:c)
        {
            ans+=it;
        }
        return ans;
          
    }
};