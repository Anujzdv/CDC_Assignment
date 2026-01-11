class Solution {
public:
    bool isMagic(vector<vector<int>>& mat, int row, int col) {
        if (mat[row + 1][col + 1] != 5)
            return false;

        vector<bool> used(10, false);

        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                int val = mat[i][j];
                if (val < 1 || val > 9 || used[val])
                    return false;
                used[val] = true;
            }
        }

        for (int i = 0; i < 3; i++) {
            if (mat[row + i][col] + mat[row + i][col + 1] + mat[row + i][col + 2] != 15)
                return false;
            if (mat[row][col + i] + mat[row + 1][col + i] + mat[row + 2][col + i] != 15)
                return false;
        }

        if (mat[row][col] + mat[row + 1][col + 1] + mat[row + 2][col + 2] != 15)
            return false;
        if (mat[row][col + 2] + mat[row + 1][col + 1] + mat[row + 2][col] != 15)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int i = 0; i + 2 < rows; i++) {
            for (int j = 0; j + 2 < cols; j++) {
                if (isMagic(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};
