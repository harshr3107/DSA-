class Solution {
public:
     

    int getmaxi(vector<int>& nums,int i,int target,vector<vector<int>>& dp)
    {
        if(i==nums.size())
        {
            if(target==0)
            {
                return 0;
            }

            return INT_MIN;
        }


        





        if(target<0)
        {
            return INT_MIN;
        }


        if(dp[i][target]!=-1)
        {
            return dp[i][target];
        }
        
        
         int take=1+getmaxi(nums,i+1,target-nums[i],dp);
        

        int nottake = 0+getmaxi(nums,i+1,target,dp);

        return  dp[i][target]=max(take,nottake);

    }


    int lengthOfLongestSubsequence(vector<int>& nums, int target) {

        int i=0;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        int h=getmaxi(nums,i,target,dp);

        return h<=0?-1:h;

       
        
    }
};