class Solution {
public:
     

     int getpath(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp)
     {
            if(i==matrix.size() || j==matrix[0].size())
            {
                return 0;
            }


            if(dp[i][j]!=-1)
            {
                return dp[i][j];
            }


            int down=0;
            int up=0;
            int right=0;
            int left=0;


            //down

            if((i+1)<matrix.size() && matrix[i+1][j]>matrix[i][j])
            {
                down = 1+getpath(matrix,i+1,j,dp);
            }

            //up

            if((i-1)>=0 && matrix[i-1][j]>matrix[i][j])
            {
                  up = 1+getpath(matrix,i-1,j,dp);
                
            }
            
             //right

            if((j+1)<matrix[i].size() && matrix[i][j+1]>matrix[i][j])
            {
                right = 1+getpath(matrix,i,j+1,dp);
            }


            //left 

            if((j-1)>=0 && matrix[i][j-1]>matrix[i][j])
            {
                left = 1+getpath(matrix,i,j-1,dp);
            }


            return dp[i][j]=max(max(up,down),max(left,right));




     }




    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int i=0;
        int j=0;

        int n = matrix.size();
        int m = matrix[0].size();

        int ans=0;

        
        
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));

        for(int i=0;i<matrix.size();i++)
        {

            for(int j=0;j<matrix[i].size();j++)
            {

                
                
                
                ans = max(ans,getpath(matrix,i,j,dp));





            }


        }

        return ans+1;



        
    }
};