class Solution {
public:
   

   void dfs(vector<vector<int>>& grid,vector<vector<int>>& g2,int i,int j,bool& flag)
   {
         if(g2[i][j]==0)
         {
            flag=false;
         }

         if((i-1)>=0 && grid[i-1][j]==1)
         {
            grid[i-1][j]=0;
            dfs(grid,g2,i-1,j,flag);
         } 

         if((i+1)<grid.size() && grid[i+1][j]==1)
         {
            grid[i+1][j]=0;
            dfs(grid,g2,i+1,j,flag);
         } 

          if((j-1)>=0 && grid[i][j-1]==1)
         {
            grid[i][j-1]=0;
            dfs(grid,g2,i,j-1,flag);
         } 

         if((j+1)<grid[i].size() && grid[i][j+1]==1)
         {
            grid[i][j+1]=0;
            dfs(grid,g2,i,j+1,flag);
         } 

   }

  

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int count=0;

        for(int i=0;i<grid2.size();i++)
        {
            for(int j=0;j<grid2[i].size();j++)
            {


                if(grid2[i][j]==1)
                {
                    bool flag = true;

                    dfs(grid2,grid1,i,j,flag);

                    if(flag==true)
                    {
                            count++;
                    }


                }

            }

        }

        return count;
        
    }
};