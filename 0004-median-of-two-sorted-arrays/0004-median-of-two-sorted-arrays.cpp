class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        // Search the smaller array so mid2 stays within bounds.
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int size1 = nums1.size();
        int size2 = nums2.size();

        int low = 0;
        int high = size1;
        int n = size1 + size2;
        int h = (n + 1) / 2;

        while (high >= low)
        {
            int mid = low + (high - low) / 2;
            int mid2 = h - mid;

            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            if (mid > 0)
            {
                l1 = nums1[mid - 1];
            }

            if (mid < size1)
            {
                r1 = nums1[mid];
            }

            if (mid2 > 0)
            {
                l2 = nums2[mid2 - 1];
            }

            if (mid2 < size2)
            {
                r2 = nums2[mid2];
            }

            if (l1 <= r2 && l2 <= r1)
            {
                if (n % 2 == 0)
                {
                    return (static_cast<double>(max(l1, l2)) + min(r1, r2)) / 2.0;
                }

                return max(l1, l2);
            }

            if (l1 > r2)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return 0.0;
    }
};