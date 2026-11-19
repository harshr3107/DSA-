class compare {
public:
    bool operator()(const pair<int, pair<int, int>>& a,
                    const pair<int, pair<int, int>>& b) const {
        return a.first > b.first;
    }
};

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // rows[i] stores unvisited column indices in row i.
        // cols[j] stores unvisited row indices in column j.
        vector<set<int>> rows(m);
        vector<set<int>> cols(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rows[i].insert(j);
                cols[j].insert(i);
            }
        }

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       compare> pq;

        pq.push({1, {0, 0}});
        rows[0].erase(0);
        cols[0].erase(0);

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int steps = it.first;
            int ci = it.second.first;
            int cj = it.second.second;

            if (ci == m - 1 && cj == n - 1) {
                return steps;
            }

            int jump = grid[ci][cj];

            // Move down in column cj.
            auto rowIt = cols[cj].upper_bound(ci);
            while (rowIt != cols[cj].end() && *rowIt <= ci + jump) {
                int i = *rowIt;
                rowIt = cols[cj].erase(rowIt); // Returns the next iterator.
                rows[i].erase(cj);
                pq.push({steps + 1, {i, cj}});
            }

            // Move right in row ci.
            auto colIt = rows[ci].upper_bound(cj);
            while (colIt != rows[ci].end() && *colIt <= cj + jump) {
                int j = *colIt;
                colIt = rows[ci].erase(colIt);
                cols[j].erase(ci);
                pq.push({steps + 1, {ci, j}});
            }
        }

        return -1;
    }
};