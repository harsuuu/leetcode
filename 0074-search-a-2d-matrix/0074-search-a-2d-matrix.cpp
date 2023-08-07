class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size())   //agr matrix koi row hi nhi ho
        {
            return false;
        }
        int n = matrix.size();     //rows
        int m = matrix[0].size();  //column
        int s=0;
        int e= m*n-1;
        int mid=s+(e-s)/2;
        while(s<=e)
        {
            if(matrix[mid/m][mid%m]==target)
            {
                return true;
            }
            else if(matrix[mid/m][mid%m] < target)
            {
                s=mid+1;
            }
            else
            {
               e=mid-1;
            }
            mid=s+(e-s)/2;
        }return false;
    }
};