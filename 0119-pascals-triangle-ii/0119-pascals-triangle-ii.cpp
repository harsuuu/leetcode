class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(rowIndex + 1);  // Adjusted to rowIndex + 1
        for (int i = 0; i <= rowIndex; i++) {   // Changed loop condition to include rowIndex
            ans[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }
        vector<int> res;
        for (int j = 0; j <= rowIndex; j++) {   // Changed condition to include rowIndex
            res.push_back(ans[rowIndex][j]);
        }
        return res;
    }
};