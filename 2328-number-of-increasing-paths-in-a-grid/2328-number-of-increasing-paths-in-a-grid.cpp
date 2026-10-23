class Solution {
public:

    int getpath(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp)
    {
        if(i==grid.size() && j==grid[0].size())
        {
            return 1;
        }

        int mod=1e9+7;


        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        long long up=0;
        long long down=0;
        long long left=0;
        long long right=0;

        //down;
        if((i+1)<grid.size() && grid[i+1][j]>grid[i][j])
        {
            down=(1+getpath(grid,i+1,j,dp))%mod;
        }

         //up;
        if((i-1)>=0 && grid[i-1][j]>grid[i][j])
        {
            up=(1+getpath(grid,i-1,j,dp))%mod;
        }

        //left

        if((j-1)>=0 && grid[i][j-1]>grid[i][j])
        {
            left=(1+getpath(grid,i,j-1,dp))%mod;
        }



          //right

        if((j+1)<grid[i].size() && grid[i][j+1]>grid[i][j])
        {
            right=(1+getpath(grid,i,j+1,dp))%mod;
        }


        

        return dp[i][j]=(down+up+left+right)%mod;

    }


    int countPaths(vector<vector<int>>& grid) {

        int i=0;
        int j=0;
        int ans=0;

        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));

        int mod=1e9+7;

        for(int i=0;i<grid.size();i++)
        {

            for(int j=0;j<grid[i].size();j++)
            {
                   ans+=1;
                   ans=(ans+getpath(grid,i,j,dp))%(mod);
            }
        
        }

        return ans;
        
    }
};