class Solution {
public:

    int getminjump(vector<int>& nums,int cind,vector<int>& dp)
    {
        if(cind>=nums.size()-1)
        {
            return 0;
        }

        if(dp[cind]!=-1)
        {
            return dp[cind];
        }

        int ans=1e9+7;

        for(int i=1;i<=nums[cind];i++)
        {

            ans = min(ans,1+getminjump(nums,cind+i,dp));

        }

        return dp[cind]=ans;

    }



    int jump(vector<int>& nums) {

        vector<int> dp(nums.size(),-1);
       return  getminjump(nums,0,dp);
        
    }
};