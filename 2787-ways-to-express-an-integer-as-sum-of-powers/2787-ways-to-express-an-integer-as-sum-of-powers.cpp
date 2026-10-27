class Solution {
public:
    const int MOD = 1'000'000'007;

    int getans(int n, int h, int x, vector<vector<int>>& dp) {
        if (n == 0) {
            return 1;
        }

        if (h == 0) {
            return 0;
        }

        if (dp[n][h] != -1) {
            return dp[n][h];
        }

        // Calculate h^x using integer multiplication.
        // Stop early if it becomes larger than n.
        long long power = 1;
        for (int i = 0; i < x; i++) {
            power *= h;
            if (power > n) {
                break;
            }
        }

        int take = 0;
        int nottake = 0;

        if (power <= n) {
            take = getans(n - power, h - 1, x, dp);
        }

        nottake = getans(n, h - 1, x, dp);

        return dp[n][h] = (take + nottake) % MOD;
    }

    int numberOfWays(int n, int x) {
        int h = n;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return getans(n, h, x, dp);
    }
};