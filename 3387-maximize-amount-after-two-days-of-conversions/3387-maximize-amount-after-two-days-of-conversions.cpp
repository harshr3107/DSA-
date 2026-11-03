class Solution {
public:
    void checkif(
        string start,
        string target,
        double cval,
        double& ans,
        unordered_set<string>& visited,
        map<string, vector<pair<string, double>>>& mp2
    ) {
        if (start == target) {
            ans = max(ans, cval);
            return;
        }

        visited.insert(start);

        for (const auto& it : mp2[start]) {
            string next = it.first;
            double rate = it.second;

            if (visited.count(next)) {
                continue;
            }

            checkif(next, target, cval * rate, ans, visited, mp2);
        }
    }

    void getallpossible(
        string start,
        string target,
        double cval,
        double& ans,
        unordered_set<string>& visited,
        map<string, vector<pair<string, double>>>& mp1,
        map<string, vector<pair<string, double>>>& mp2
    ) {
        if (visited.count(start)) {
            return;
        }

        visited.insert(start);

        // Try converting this day 1 amount back to the initial
        // currency using day 2 rates.
        unordered_set<string> visited2;
        checkif(start, target, cval, ans, visited2, mp2);

        // Continue exploring day 1 conversions.
        for (const auto& it : mp1[start]) {
            string next = it.first;
            double rate = it.second;

            if (visited.count(next)) {
                continue;
            }

            getallpossible(
                next, target, cval * rate, ans, visited, mp1, mp2
            );
        }
    }

    double maxAmount(
        string initialCurrency,
        vector<vector<string>>& pairs1,
        vector<double>& rates1,
        vector<vector<string>>& pairs2,
        vector<double>& rates2
    ) {
        map<string, vector<pair<string, double>>> mp1;
        map<string, vector<pair<string, double>>> mp2;

        for (int i = 0; i < pairs1.size(); i++) {
            string a = pairs1[i][0];
            string b = pairs1[i][1];

            mp1[a].push_back({b, rates1[i]});
            mp1[b].push_back({a, 1.0 / rates1[i]});
        }

        for (int i = 0; i < pairs2.size(); i++) {
            string a = pairs2[i][0];
            string b = pairs2[i][1];

            mp2[a].push_back({b, rates2[i]});
            mp2[b].push_back({a, 1.0 / rates2[i]});
        }

        double ans = 1.0;  // Also accounts for making no conversions.
        unordered_set<string> visited;

        getallpossible(
            initialCurrency,
            initialCurrency,
            1.0,
            ans,
            visited,
            mp1,
            mp2
        );

        return ans;
    }
};