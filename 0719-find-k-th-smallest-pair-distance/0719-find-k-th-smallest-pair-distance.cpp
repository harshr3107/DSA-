class Solution {
public:
    bool ispossible(const vector<int>& sorted, int mid, int k)
    {
        int left = 0;

        for (int right = 0; right < sorted.size(); right++)
        {
            while (sorted[right] - sorted[left] > mid)
            {
                left++;
            }

            // Every index from left to right - 1 pairs with right.
            k -= right - left;

            if (k <= 0)
            {
                return true;
            }
        }

        return false;
    }

    int smallestDistancePair(vector<int>& nums, int k)
    {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int mini = sorted.front();
        int maxi = sorted.back();

        int low = 0;
        int high = maxi - mini;
        int ans = 0;

        while (high >= low)
        {
            int mid = low + (high - low) / 2;

            if (ispossible(sorted, mid, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};