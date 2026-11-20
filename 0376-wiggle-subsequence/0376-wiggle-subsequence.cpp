class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

         vector<vector<int>> dp(nums.size(),vector<int>(2,1));

         int maxi=1;

         for(int i=0;i<nums.size();i++)
         {
            for(int j=0;j<i;j++)
            {
                if((nums[i]-nums[j])>0)
                {
                    dp[i][1]=max(dp[i][1],1+dp[j][0]);

                }else if((nums[i]-nums[j])<0)
                {
                     dp[i][0]=max(dp[i][0],1+dp[j][1]);

                }

            }

            maxi = max(maxi,max(dp[i][1],dp[i][0]));



         }

         return maxi;

        
        
    }
};