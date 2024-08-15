//Simple Approach - Counting left and right values
//T.C : O(rows*cols)
//S.C : O(rows*cols)
class Solution {
public:

    void numberOfIslandsDFS(vector<vector<int>>& matrix, int i, int j) {
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == 1)
            return;
        
        matrix[i][j] = 1; //mark visited

        numberOfIslandsDFS(matrix,i+1,j);
        numberOfIslandsDFS(matrix,i-1,j);
        numberOfIslandsDFS(matrix,i,j+1);
        numberOfIslandsDFS(matrix,i,j-1);
        
    }

    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int regions = 0;

        vector<vector<int>> matrix(rows*3, vector<int>(cols*3, 0)); //M * N

        //Populate the matrix using the mapping of '/', '\'

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '/') {
                    matrix[i*3][j*3 + 2] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3] = 1;
                } else if(grid[i][j] == '\\') {
                    matrix[i*3][j*3] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3+2] = 1;
                }
            }
        }


        //Apply concept of "Number of Islands"
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) { //DFS
                    numberOfIslandsDFS(matrix, i, j);
                    regions += 1;
                }
            }
        }

        return regions;

    }
}; 