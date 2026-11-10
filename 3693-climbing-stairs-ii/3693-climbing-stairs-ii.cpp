class Solution {
public:
 //getans(costs,n);

    int getans(vector<int>& costs,int n,vector<int>& dp)
    {
        if(n==-1)
        {
            return 0;
        }

        if(n<-1)
        {
            return 1e9+7;
        }

        if(dp[n]!=-1)
        {
            return dp[n];
        }


        int take1 = (costs[n]+(1*1))+getans(costs,n-1,dp);
        int take2 = (costs[n]+(2*2))+getans(costs,n-2,dp);
        int take3 = (costs[n]+(3*3))+getans(costs,n-3,dp);

        return dp[n]=min(take1,min(take2,take3));

    }


    int climbStairs(int n, vector<int>& costs) {
        
        vector<int> dp(n+1,-1);
        return getans(costs,n-1,dp);
        
    }
};