class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r)
    {
        int n = nums.size();

        if (n < l)
        {
            return -1;
        }

        int ans = INT_MAX;

        for (int len = l; len <= r && len <= n; len++)
        {
            int i = 0;
            int j = 0;
            int csum = 0;

            while (j < len)
            {
                csum += nums[j];
                j++;
            }

            if (csum > 0)
            {
                ans = min(ans, csum);
            }

            while (j < n)
            {
                csum -= nums[i];
                csum += nums[j];
                i++;
                j++;

                if (csum > 0)
                {
                    ans = min(ans, csum);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};