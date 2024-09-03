class Solution {
public:
    int tabulation(string text1, string text2,vector<vector<int>>&dp)
    {
        int n = text1.length();
        int m = text2.length();
        //vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int j=0;j<=m;j++)   dp[0][j]=0;
        for(int i=0;i<=n;i++)   dp[i][0]=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                //not matching
                else dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]); 
            }
        }
    return dp[n][m];
    }
    string shortestCommonSupersequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans = tabulation(text1,text2,dp);

        //LENGTH OF SHORTEST COMMON SUPERSUBSEQUENCE
        cout<<(n+m) - ans<<endl;
        string res ="";
        int i=n,j=m; 
        while(i>0 && j>0)
        {
            if(text1[i-1]==text2[j-1])
            {
                res+=text1[i-1];
                //index--;
                i--,j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])      //up to neeche bala  le liya.
            {
                res+=text1[i-1];
                i--;
            }   
            else{                               //left gye to right bala lenge.
                res+=text2[j-1];
                j--;
            }
        }
        //after traversing dp table, ek element rh gya koi bhi ek string ka use store krke reverse krdo.
        while(i>0){
            res+=text1[i-1];
            i--;
        }
        while(j>0)
        {
            res+=text2[j-1];
            j--;
        }
    reverse(res.begin(),res.end());
    return res;
    }
};