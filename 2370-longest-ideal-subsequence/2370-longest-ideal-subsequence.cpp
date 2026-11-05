class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        int ans = 0;

        for (char ch : s) {
            int current = ch - 'a';
            int bestPrevious = 0;

            // Find the best subsequence ending with a compatible letter.
            for (int prev = max(0, current - k); prev <= min(25, current + k); prev++) {
                bestPrevious = max(bestPrevious, dp[prev]);
            }

            dp[current] = bestPrevious + 1;
            ans = max(ans, dp[current]);
        }

        return ans;
    }
};