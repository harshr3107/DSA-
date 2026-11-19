class Solution {
public:
    int getminchanges(string& s, int i) {
        int ans = 0;
        int n = s.size();

        while (i < n) {
            if (s[i] != s[i + 1]) {
                ans++;
            }
            i += 2;
        }

        return ans;
    }

    int minChanges(string s) {
        return getminchanges(s, 0);
    }
};