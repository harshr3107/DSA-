class Solution {
public:
    
    

    int getans(int n,int a,vector<int>& dp)
    {
        if(n<=1)
        {
            return 1;
        }

        if(dp[n]!=-1)
        {
            return dp[n];
        }

        int ans=1;

        for(int i=1;i<=n;i++)
        {
              if(a==0 && i==n)
              {
                 continue;
              }
           

                ans=max(ans,i*getans(n-i,a+1,dp));
        }

        return dp[n]=ans;



    }


    int integerBreak(int n) {

        vector<int> dp(n+1,-1);
        return getans(n,0,dp);
        
    }
};