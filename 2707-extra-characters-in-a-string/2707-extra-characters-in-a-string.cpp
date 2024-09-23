class Solution {
public:
    int solve(int idx, string s,int n, set<string>&st,vector<int>&dp){
        if(idx>=n)  return 0;

        if(dp[idx]!=-1)     return dp[idx];

        int minExtra = n;   //JYADA SE JYADA ITNE EXTRA HO SKTE HAI.
        string temp="";
        for(int i=idx;i<n;i++)
        {   
            temp+=s[i];
            int currExtra;
            if(st.find(temp)==st.end())     //agr nhi present in dictionary to extra hai mtlb
            {
                currExtra=temp.size();      //mtlb itni length bali extra hai.
            }
            else{
                currExtra=0;                //set m present hai to 0 extra character.
            }

            //remaining extra ke liye call mar do.
            int remainingExtra = solve(i+1,s,n,st,dp);

            int totalExtra = currExtra + remainingExtra;

            minExtra = min(minExtra,totalExtra);
        }
    return dp[idx] = minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int>dp(n,-1);
        set<string>st(dictionary.begin(),dictionary.end());
        return solve(0,s,n,st,dp); 
    }
};