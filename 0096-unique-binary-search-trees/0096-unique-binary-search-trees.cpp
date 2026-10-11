class Solution {
public:
    
    int getans(int n,vector<int>& dp)
    {

        if(n<=1)
        {
            return 1;
        }

        if(dp[n]!=-1)
        {
            return dp[n];
        }

        int ans=0;

        for(int i=1;i<=n;i++)
        {
                ans+=(getans(i-1,dp)*getans(n-i,dp));
        }

        return dp[n]=ans;

    }

    int numTrees(int n) {

           vector<int> dp(n+1,-1);

            return getans(n,dp);
       
    }
};