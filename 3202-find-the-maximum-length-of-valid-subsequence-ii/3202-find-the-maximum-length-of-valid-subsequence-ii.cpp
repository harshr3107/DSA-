class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {

         vector<vector<int>> dp(nums.size(),vector<int>(k+1,1));
         int ans=1;

         for(int i=0;i<nums.size();i++)
         {
            for(int j=0;j<i;j++)
            {
                int l = (nums[i]+nums[j])%k;

                dp[i][l]=max(dp[i][l],1+dp[j][l]);
                ans=max(ans,dp[i][l]);

            }
            
        }


        return ans;
        
    }
};