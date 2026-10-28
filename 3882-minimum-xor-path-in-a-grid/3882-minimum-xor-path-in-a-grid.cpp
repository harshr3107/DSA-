class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bitset<1024>>> dp(m,vector<bitset<1024>>(n));

        dp[0][0][grid[0][0]]=1;


        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                bitset<1024> up;
                bitset<1024> left;

                if(i-1>=0)
                {
                    up=dp[i-1][j];

                }


                if(j-1>=0)
                {
                    left=dp[i][j-1];
                }



                bitset<1024> req = up|left;

                for(int k=0;k<1024;k++)
                {
                    if(req[k]==1)
                    {
                       int h = grid[i][j]^k;

                       dp[i][j][h]=1;

                    }

                }




            }

        }


        for(int i=0;i<1024;i++)
        {
            if(dp[m-1][n-1][i]==1)
            {
                return i;
            }

        }


        return -1;



        

        
    }
};