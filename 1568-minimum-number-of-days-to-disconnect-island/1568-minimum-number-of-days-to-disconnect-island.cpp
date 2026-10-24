class Solution {
public:
    int numberOfIslands(vector<vector<int>> grid, int n, int m) {
        int islands = 0;
        vector<int> dr = {0, 1, 0, -1}, dc = {1, 0, -1, 0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    islands++;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 0;

                    while (!q.empty()) {
                        auto [row, col] = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nr = row + dr[k];
                            int nc = col + dc[k];

                            if (nr < 0 || nr >= n || nc < 0 || nc >= m ||
                                grid[nr][nc] == 0) {
                                continue;
                            }

                            grid[nr][nc] = 0;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }

        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Already disconnected
        int num_islands = numberOfIslands(grid, n, m);

        if (num_islands != 1) {
            return 0;
        }

        // Try removing every land cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {
                    // Remove this land cell
                    grid[i][j] = 0;

                    // Check if the island got disconnected
                    int num_islands = numberOfIslands(grid, n, m);

                    if (num_islands != 1) {
                        return 1;
                    }

                    // Restore the cell
                    grid[i][j] = 1;
                }
            }
        }

        // No single cell could disconnect the island
        return 2;
    }
};