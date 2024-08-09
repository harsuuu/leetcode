class Solution {
public:
bool isMagic(int i, int j, vector<vector<int>>& grid) {
    // Check for distinctness and valid range
    vector<int> nums(10, 0);  // Index 0 is unused

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            int val = grid[i + x][j + y];
            if (val < 1 || val > 9 || nums[val] > 0) {
                return false;  // Not distinct or not in range
            }
            nums[val]++;
        }
    }

    // Calculate the target sum using the first row
    int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
    
     // Check all rows
    for (int x = 0; x < 3; x++) {
        int rowSum = 0;
        for (int y = 0; y < 3; y++) {
            rowSum += grid[i + x][j + y];
        }
        if (rowSum != sum) return false;
    }

    // Check all columns
    for (int y = 0; y < 3; y++) {
        int colSum = 0;
        for (int x = 0; x < 3; x++) {
            colSum += grid[i + x][j + y];
        }
        if (colSum != sum) return false;
    }


    // Check diagonals
    int d1Sum = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
    int d2Sum = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];
    if (d1Sum != sum || d2Sum != sum) return false;

    return true;
}

int numMagicSquaresInside(vector<vector<int>>& grid) {
    int cnt = 0;
    int n = grid.size();
    int m = grid[0].size();

    // Loop over each possible top-left corner of a 3x3 grid
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            if (isMagic(i, j, grid)) {
                cnt++;
            }
        }
    }

    return cnt;
}

};