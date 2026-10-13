class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                int left = 1e9;
                int down = matrix[i][j] + dp[i + 1][j];
                int right = 1e9;

                if (j > 0) {
                    left = matrix[i][j] + dp[i + 1][j - 1];
                }

                if (j + 1 < m) {
                    right = matrix[i][j] + dp[i + 1][j + 1];
                }

                dp[i][j] = min(left, min(down, right));
            }
        }

        int ans = INT_MAX;

        for (int j = 0; j < m; j++) {
            ans = min(ans, dp[0][j]);
        }

        return ans;
    }
};