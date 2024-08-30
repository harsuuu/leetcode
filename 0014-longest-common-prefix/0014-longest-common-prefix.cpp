class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int a=strs.size();
        //we check only first and last string after the sorting.
        string n=strs[0];
        string m=strs[a-1];
        string ans="";
        for(int i=0;i<n.size();i++){
            if(n[i]==m[i])
            {
                ans+=n[i];
            }
            else break;
        }
        return ans;
    }
};
