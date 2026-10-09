class Solution {
public:
    int mod = 1e9 + 7;

    // Check whether the rectangle contains an apple.
    bool checkapple(vector<string>& pizza,
                    int istart, int jstart, int iend, int jend)
    {
        for (int i = istart; i <= iend; i++) {
            for (int j = jstart; j <= jend; j++) {
                if (pizza[i][j] == 'A') {
                    return true;
                }
            }
        }

        return false;
    }

    int getways(vector<string>& pizza, int istart, int jstart, int k,
                vector<vector<vector<int>>>& dp)
    {
        int rows = pizza.size();
        int cols = pizza[0].size();

        if (istart >= rows || jstart >= cols) {
            return 0;
        }

        if (k == 1) {
            return checkapple(
                pizza, istart, jstart, rows - 1, cols - 1
            ) ? 1 : 0;
        }

        if (dp[istart][jstart][k] != -1) {
            return dp[istart][jstart][k];
        }

        int ways = 0;

        // We cut horizontally
        for (int x = istart; x < rows - 1; x++) {
            if (checkapple(pizza, istart, jstart, x, cols - 1)) {
                ways = (ways + getways(
                    pizza, x + 1, jstart, k - 1, dp
                )) % mod;
            }
        }

        // Vertically
        for (int x = jstart; x < cols - 1; x++) {
            if (checkapple(pizza, istart, jstart, rows - 1, x)) {
                ways = (ways + getways(
                    pizza, istart, x + 1, k - 1, dp
                )) % mod;
            }
        }

        return dp[istart][jstart][k] = ways;
    }

    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size();
        int cols = pizza[0].size();

        vector<vector<vector<int>>> dp(
            rows, vector<vector<int>>(cols, vector<int>(k + 1, -1))
        );

        int istart = 0;
        int jstart = 0;

        return getways(pizza, istart, jstart, k, dp);
    }
};