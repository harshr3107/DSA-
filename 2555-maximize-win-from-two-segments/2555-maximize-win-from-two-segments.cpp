class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        vector<int> best(n + 1, 0);

        int left = 0;
        int answer = 0;
        int right = 0;

        while (right < n) {
            while (prizePositions[right] - prizePositions[left] > k) {
                left++;
            }

            int currentSegmentCount = right - left + 1;
            answer = max(answer, best[left] + currentSegmentCount);
            best[right + 1] = max(best[right], currentSegmentCount);

            right++;
        }

        return answer;
    }
};