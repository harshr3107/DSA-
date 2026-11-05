class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evenCount = 0;
        int oddCount = 0;
        int alternatingLength = 0;
        int previousParity = -1;

        for (int num : nums) {
            int parity = num % 2;

            if (parity == 0) {
                evenCount++;
            } else {
                oddCount++;
            }

            // Keep one number from each consecutive parity run.
            if (parity != previousParity) {
                alternatingLength++;
                previousParity = parity;
            }
        }

        return max({evenCount, oddCount, alternatingLength});
    }
};