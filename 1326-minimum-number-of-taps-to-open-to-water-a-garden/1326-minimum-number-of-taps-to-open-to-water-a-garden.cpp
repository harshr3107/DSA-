class Solution {
public:
    static constexpr int INF = 1000000000;

    int getmin(vector<pair<int, int>>& v, int i, int lcover, int n,
               vector<unordered_map<int, int>>& dp) {
        if (lcover == n) {
            return 0;
        }

        if (i == v.size() || v[i].first > lcover) {
            return INF;
        }

        auto it = dp[i].find(lcover);
        if (it != dp[i].end()) {
            return it->second;
        }

        int take = INF;
        if (v[i].second > lcover) {
            take = 1 + getmin(v, i + 1, v[i].second, n, dp);
        }

        int nottake = getmin(v, i + 1, lcover, n, dp);

        return dp[i][lcover] = min(take, nottake);
    }

    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> v;

        for (int i = 0; i < ranges.size(); i++) {
            int left = max(i - ranges[i], 0);
            int right = min(n, i + ranges[i]);
            v.push_back(make_pair(left, right));
        }

        sort(v.begin(), v.end());

        vector<unordered_map<int, int>> dp(v.size());
        int h = getmin(v, 0, 0, n, dp);

        return h >= INF ? -1 : h;
    }
};