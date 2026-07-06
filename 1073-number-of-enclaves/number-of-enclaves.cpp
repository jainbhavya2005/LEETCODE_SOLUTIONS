class Solution {
    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 &&
                ncol < grid[0].size()) {
                if (grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                    dfs(nrow, ncol, grid, vis);
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int col = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(rows, vector<int>(col, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {
                if ((i == 0 || i == rows - 1 || j == 0 || j == col - 1)) {
                    if (grid[i][j] == 1 && vis[i][j] == 0) {
                        dfs(i, j, grid, vis);
                    }
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};