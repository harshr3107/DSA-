class Solution {
public:
    int minMoves(vector<int>& nums) {

        int h = *max_element(nums.begin(),nums.end());
        int ans=0;

        for(auto it: nums)
        {
            ans=ans+(h-it);
        }

        return ans;
        
    }
};