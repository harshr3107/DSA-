class Solution {
public:
    static const int MOD = 1'000'000'007;

    // Returns limit + 1 if base^exp is greater than limit.
    long long powerCapped(int base, int exp, int limit) {
        long long value = 1;

        for (int i = 0; i < exp; i++) {
            if (value > limit / base) {
                return limit + 1;
            }
            value *= base;
        }

        return value;
    }

    int getans(int n, int h, int x, vector<vector<int>>& dp) {
        if (n == 0) return 1;
        if (h == 0) return 0;

        if (dp[n][h] != -1) {
            return dp[n][h];
        }

        int take = 0;
        int nottake = getans(n, h - 1, x, dp);

        long long power = powerCapped(h, x, n);
        if (power <= n) {
            take = getans(n - power, h - 1, x, dp);
        }

        return dp[n][h] = (take + nottake) % MOD;
    }

    int numberOfWays(int n, int x) {
        if (n == 0) return 1;

        // Find the largest h for which h^x <= n.
        int h = 0;
        while (powerCapped(h + 1, x, n) <= n) {
            h++;
        }

        vector<vector<int>> dp(n + 1, vector<int>(h + 1, -1));
        return getans(n, h, x, dp);
    }
};