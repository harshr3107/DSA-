class Solution {
public:
    vector<vector<int>> freq;

    int getways(vector<string>& words, int lind, string& target,
                int tind, vector<vector<int>>& dp)
    {
        if (tind == target.length())
        {
            return 1;
        }

        if (words[0].length() - lind < target.length() - tind)
        {
            return 0;
        }

        if (dp[lind][tind] != -1)
        {
            return dp[lind][tind];
        }

        const int mod = 1000000007;

        // Skip column lind and keep looking for target[tind].
        long long ans = getways(words, lind + 1, target, tind, dp);

        // Use column lind to match target[tind].
        int count = freq[lind][target[tind] - 'a'];

        if (count > 0)
        {
            ans += 1LL * count *
                   getways(words, lind + 1, target, tind + 1, dp);
        }

        return dp[lind][tind] = ans % mod;
    }

    int numWays(vector<string>& words, string target)
    {
        int lind = 0;
        int tind = 0;
        int columns = words[0].length();

        freq.assign(columns, vector<int>(26, 0));

        for (const string& word : words)
        {
            for (int j = 0; j < columns; j++)
            {
                freq[j][word[j] - 'a']++;
            }
        }

        vector<vector<int>> dp(columns, vector<int>(target.length(), -1));
        return getways(words, lind, target, tind, dp);
    }
};