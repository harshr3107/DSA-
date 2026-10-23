class Solution {
public:
    
   
   int getans(int n,int h,vector<vector<int>>& dp)
   {

      

    



      if(n==0)
      {
         return 0;
      }


      if(h==0)
      {
        return 1e9+7;
      }

      if(dp[n][h]!=-1)
      {
        return dp[n][h];
      }

      

      int take=1e9+7;
      int nottake=1e9+7;

      
      if(n-(h*h)>=0)
      {
            take = 1+getans(n-h*h,h,dp);
      }

      nottake = getans(n,h-1,dp);

      return dp[n][h]=min(take,nottake);




            
             

   }


    int numSquares(int n) {

        int h=0;
        int l=ceil(sqrt(n));

        vector<vector<int>> dp(n+1,vector<int>(l+1,-1));

        return getans(n,l,dp);
        
    }
};