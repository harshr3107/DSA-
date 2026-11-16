class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums)
    {
        const int mod = 1'000'000'007;
        long long ans = 1;
        int prev = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                if (prev != -1)
                {
                    ans = (ans * (i - prev)) % mod;
                }

                prev = i;
            }
        }

        return prev == -1 ? 0 : ans;
    }
};