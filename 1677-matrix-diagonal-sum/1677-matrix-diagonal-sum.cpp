class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
            sum=sum+mat[i][i]+mat[i][n-1-i];
        }
        if(n%2==0)  // agr even hogi to koi na.
        {
            return sum;
        }
        else // agr odd hogi to middle bala minus kr denge.
        {
            return sum-mat[n/2][n/2];
        }
        
    }
};