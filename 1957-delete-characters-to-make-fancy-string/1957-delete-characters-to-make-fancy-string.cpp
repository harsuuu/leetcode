class Solution {
public:
    string makeFancyString(string s) {
        int frq=1;
        string ans="";
        ans.push_back(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==ans.back())
            {
                ans.push_back(s[i]);
                frq++;
                if(frq>2){
                    ans.pop_back();
                }
            }else{
                ans.push_back(s[i]);
                frq=1;
            }
        }
    return ans;
    }
};