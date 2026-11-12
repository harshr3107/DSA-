class Solution {
public:
    long long getans(int& cost1, int& cost2, int& cost3,
                     int need1, int need2)
    {
        int common = min(need1, need2);

        // t1: Buy all items separately.
        long long t1 = 1LL * need1 * cost1
                     + 1LL * need2 * cost2;

        // t2: Buy type 3 for the shared need, then buy the rest separately.
        long long t2 = 1LL * common * cost3
                     + 1LL * (need1 - common) * cost1
                     + 1LL * (need2 - common) * cost2;

        // t3: Buy type 3 until both needs are met.
        long long t3 = 1LL * max(need1, need2) * cost3;

        return min(t1, min(t2, t3));
    }

    long long minimumCost(int cost1, int cost2, int cost3,
                          int need1, int need2)
    {
        return getans(cost1, cost2, cost3, need1, need2);
    }
};