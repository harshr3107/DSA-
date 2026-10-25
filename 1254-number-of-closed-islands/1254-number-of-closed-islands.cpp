class Solution {
public:

   bool checkifisland(vector<vector<int>>& grid,int i,int j)
   {

          if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size())
          {
            return false;
          }
          

          bool ans=true;
          

          if(grid[i][j]==0)
          {
              grid[i][j]=1;

              ans=(ans&checkifisland(grid,i+1,j));

              ans = (ans&checkifisland(grid,i-1,j));

              ans = (ans&checkifisland(grid,i,j-1));

              ans = (ans&checkifisland(grid,i,j+1));
              
          }

          


          return ans;

   }


    int closedIsland(vector<vector<int>>& grid) {

        int ans=0;
       

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==0)
                {


                    if(checkifisland(grid,i,j)==true)
                    {
                        ans++;
                    }

                }

            }

        }

        return ans;



        
    }
};