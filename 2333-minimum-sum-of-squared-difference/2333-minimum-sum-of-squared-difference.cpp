class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        vector<int> dif(100001, 0);

        for (int i = 0; i < nums1.size(); i++) {
            dif[abs(nums1[i] - nums2[i])]++;
        }

        long long k = (long long)k1 + k2;

        for (int i = 100000; i >= 1; i--) {
            long long oper = min((long long)dif[i], k);

            dif[i] -= oper;
            dif[i - 1] += oper;
            k -= oper;

            if (k == 0) break;
        }

        long long ans = 0;

        for (int i = 1; i <= 100000; i++) {
            ans += 1LL * i * i * dif[i];
        }

        return ans;
    }
};