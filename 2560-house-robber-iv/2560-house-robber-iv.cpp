class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int cap = left + (right - left) / 2;
            int count = 0;

            for (int i = 0; i < nums.size();) {
                if (nums[i] <= cap) {
                    count++;
                    i += 2;  // Skip the adjacent house
                } else {
                    i++;
                }
            }

            if (count >= k) {
                right = cap;      // This capability works; try a smaller one
            } else {
                left = cap + 1;   // Need a larger capability
            }
        }

        return left;
    }
};