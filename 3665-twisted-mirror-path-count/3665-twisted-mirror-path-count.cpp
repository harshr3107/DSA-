class Solution {
public:

    
   

    int getways(vector<vector<int>>& grid,int i,int j,int dir,vector<vector<vector<int>>>& dp)
    {
        if(i==grid.size()-1 && j==grid[i].size()-1)
        {
            return 1;
        }

        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size())
        {
            return 0;
        }


        if(dp[i][j][dir+1]!=-1)
        {
            return dp[i][j][dir+1];
        }


        int ways=0;
        int mod=1e9+7;

        if(grid[i][j]==1)
        {
            if(dir==1)
            {
                return  dp[i][j][dir+1]=getways(grid,i,j+1,0,dp);
            }else{

                return  dp[i][j][dir+1]=getways(grid,i+1,j,1,dp);
            }

        }


       

        ways=(ways+getways(grid,i+1,j,1,dp))%mod;
        ways=(ways+getways(grid,i,j+1,0,dp))%mod;

        return  dp[i][j][dir+1]=ways%mod;

       

    }



    int uniquePaths(vector<vector<int>>& grid) {

        int i=0;
        int j=0;

        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(3,-1)));

        return getways(grid,i,j,-1,dp);
        
    }
};