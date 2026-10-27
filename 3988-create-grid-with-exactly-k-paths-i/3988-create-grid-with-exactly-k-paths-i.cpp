class Solution {
public:
    void combine(const vector<string>& ans, vector<string>& fans) {
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].length(); j++) {
                if (ans[i][j] == '.') {
                    fans[i][j] = '.';
                }
            }
        }
    }

    // Count paths through the open cells.
    long long countPaths(const vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '#') {
                    continue;
                }

                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    if (i > 0) dp[i][j] += dp[i - 1][j];
                    if (j > 0) dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }

    // Save every possible path.
    void getans( vector<string>& ans,int i,int j,int m,int n,vector<vector<string>>& allPaths
    ) {
        if (i == m - 1 && j == n - 1) {
            allPaths.push_back(ans);
            return;
        }

        // Move down.
        if (i + 1 < m) {
            ans[i + 1][j] = '.';
            getans(ans, i + 1, j, m, n, allPaths);
            ans[i + 1][j] = '#';
        }

        // Move right.
        if (j + 1 < n) {
            ans[i][j + 1] = '.';
            getans(ans, i, j + 1, m, n, allPaths);
            ans[i][j + 1] = '#';
        }
    }

    // Try including or skipping each saved path.
    bool choosePaths(int index,vector<vector<string>>& allPaths, vector<string>& fans,int k,vector<string>& answer) 
    {
        long long ways = countPaths(fans);

        if (ways == k) {
            answer = fans;
            return true;
        }

        if (ways > k || index == allPaths.size()) {
            return false;
        }

        // Try adding this path to fans.
        vector<string> combined = fans;
        combine(allPaths[index], combined);

        if (countPaths(combined) <= k &&
            choosePaths(index + 1, allPaths, combined, k, answer)) {
            return true;
        }

        // If adding it doesn't work, skip it.
        return choosePaths(index + 1, allPaths, fans, k, answer);
    }

    vector<string> createGrid(int m, int n, int k) {
        if (m <= 0 || n <= 0 || k < 0) {
            return {};
        }

        vector<string> ans(m, string(n, '#'));
        vector<string> fans(m, string(n, '#'));

        if (k == 0) {
            return fans;
        }

        ans[0][0] = '.';

        vector<vector<string>> allPaths;
        getans(ans, 0, 0, m, n, allPaths);

        vector<string> answer;

        if (choosePaths(0, allPaths, fans, k, answer)) {
            return answer;
        }

        return {}; // No grid with exactly k paths was found.
    }
};