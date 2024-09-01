class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans;
        if(original.size()!=m*n)       return ans;
        for (int i = 0; i < m; ++i) {
            // Create a sub-array from `original` starting at `i * n`
            vector<int> row;
            for (int j = 0; j < n; ++j) {
                row.push_back(original[i * n + j]);
            }
            ans.push_back(row);  // Append the row to the result
        }
    return ans;
    }
};