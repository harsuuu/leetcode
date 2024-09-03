class Solution {
public:
    int solve(string &s1, string &s2, int i, int j)
    {
        //base case
        if (i < 0) {  // if s1 is exhausted, delete all remaining characters of s2
        int sum = 0;
        for (int k = 0; k <= j; k++) {
            sum += s2[k];
        }
        return sum;
        }
        if (j < 0) {  // if s2 is exhausted, delete all remaining characters of s1
        int sum = 0;
        for (int k = 0; k <= i; k++) {
            sum += s1[k];
        }
        return sum;
    }
        //matched
        if(s1[i]==s2[j])
        {
            return solve(s1,s2,i-1,j-1);
        }
        //not match --> then there will be two condition
        int delete_i = s1[i] + solve(s1,s2,i-1,j);
        int delete_j = s2[j] + solve(s1,s2,i,j-1);
    
    return min(delete_i,delete_j);
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
      
        return solve(s1,s2,n-1,m-1);
    }
};