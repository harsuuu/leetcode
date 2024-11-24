class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size(); 
        int cnt = 0;
        //observation 1 : -> if matrix m odd time, negative element hai to jo sbse chota element hoga bo hi minus hoga and sbko sum krdo bo max answer aayega.
        //observation 2 : -> if matrix m even time, negative element hai to unhe direct add krdo qki after some operation bo sb positive bn jayenge.
        long long sum=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=abs(matrix[i][j]);
                mini=min(mini,abs(matrix[i][j]));
                if(matrix[i][j]<0)
                {
                    cnt++;
                }
            }
        }
        if(cnt%2==0){
            return sum;
        }
    return sum-2*mini;
    }
};