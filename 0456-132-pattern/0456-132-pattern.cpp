class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        long long two = LLONG_MIN;

        for (int i = static_cast<int>(nums.size()) - 1; i >= 0; i--) {
            if (nums[i] < two) {
                return true;
            }

            while (!st.empty() && nums[i] > st.top()) {
                two = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};