class Solution {
    void bfs(int row, int col, vector<vector<int>>& vis,vector<vector<char>>& grid) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        q.push({row, col});
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int drow[] = {-1, 1, 0, 0};
int dcol[] = {0, 0, -1, 1};
for (int k = 0; k < 4; k++) {
    int nrow = row + drow[k];
    int ncol = col + dcol[k];
    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
        grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
        vis[nrow][ncol] = 1;
        q.push({nrow, ncol});
    }
}
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        // n rows
        int m = grid[0].size();
        // m colunms
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return count;
    }
};