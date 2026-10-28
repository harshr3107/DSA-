class compare {
public:
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return a[2] < b[2]; // Max-heap by safeness
    }
};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<pair<int, int>> theif;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    theif.push_back({i, j});
                }
            }
        }

        // Find each cell's distance to its nearest thief.
        vector<vector<int>> safeness(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (auto cell : theif) {
            safeness[cell.first][cell.second] = 0;
            q.push(cell);
        }

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Left
            if (c - 1 >= 0 && safeness[r][c - 1] == -1) {
                safeness[r][c - 1] = safeness[r][c] + 1;
                q.push({r, c - 1});
            }

            // Right
            if (c + 1 < n && safeness[r][c + 1] == -1) {
                safeness[r][c + 1] = safeness[r][c] + 1;
                q.push({r, c + 1});
            }

            // Top
            if (r - 1 >= 0 && safeness[r - 1][c] == -1) {
                safeness[r - 1][c] = safeness[r][c] + 1;
                q.push({r - 1, c});
            }

            // Bottom
            if (r + 1 < n && safeness[r + 1][c] == -1) {
                safeness[r + 1][c] = safeness[r][c] + 1;
                q.push({r + 1, c});
            }
        }

        priority_queue<vector<int>, vector<vector<int>>, compare> pq;

        int l = safeness[0][0];
        vector<int> v = {0, 0, l};
        pq.push(v);

        vector<vector<int>> distance(n, vector<int>(n, -1));
        distance[0][0] = l;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int i = it[0];
            int j = it[1];
            int cans = it[2];

            if (distance[i][j] > cans) {
                continue;
            }

            if (i == n - 1 && j == n - 1) {
                return cans;
            }

            // Left
            if (j - 1 >= 0) {
                l = min(safeness[i][j - 1], cans);

                if (distance[i][j - 1] < l) {
                    distance[i][j - 1] = l;
                    pq.push({i, j - 1, l});
                }
            }

            // Right
            if (j + 1 < n) {
                l = min(safeness[i][j + 1], cans);

                if (distance[i][j + 1] < l) {
                    distance[i][j + 1] = l;
                    pq.push({i, j + 1, l});
                }
            }

            // Top
            if (i - 1 >= 0) {
                l = min(safeness[i - 1][j], cans);

                if (distance[i - 1][j] < l) {
                    distance[i - 1][j] = l;
                    pq.push({i - 1, j, l});
                }
            }

            // Bottom
            if (i + 1 < n) {
                l = min(safeness[i + 1][j], cans);

                if (distance[i + 1][j] < l) {
                    distance[i + 1][j] = l;
                    pq.push({i + 1, j, l});
                }
            }
        }

        return 0;
    }
};