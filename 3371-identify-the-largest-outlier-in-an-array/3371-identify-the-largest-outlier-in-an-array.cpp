class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int tsum = accumulate(nums.begin(), nums.end(), 0);

        for (int i =nums.size() - 1; i >= 0; i--) {
            int remaining = tsum - nums[i];

            if (remaining % 2 != 0) {
                continue;
            }

            int sumElement = remaining / 2;
            auto range = equal_range(nums.begin(), nums.end(), sumElement);
            int count = range.second - range.first;

            // If the values are equal, we need two separate copies.
            int needed = (sumElement == nums[i]) ? 2 : 1;
            if (count >= needed) {
                return nums[i];
            }
        }

        return 0; // The problem guarantees a valid outlier.
    }
};