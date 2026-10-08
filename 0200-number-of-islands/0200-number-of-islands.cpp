class Solution {
public:
    
    void markall(vector<vector<char>>& grid,int i,int j)
    {
        

        if((i-1)>=0 && grid[i-1][j]=='1')
        {
            grid[i-1][j]='0';
            markall(grid,i-1,j);
        }

        if((i+1)<grid.size() && grid[i+1][j]=='1')
        {
            grid[i+1][j]='0';
            markall(grid,i+1,j);
        }

        if((j-1)>=0 && grid[i][j-1]=='1')
        {
            grid[i][j-1]='0';
            markall(grid,i,j-1);
        }


        if((j+1)<grid[i].size() && grid[i][j+1]=='1')
        {
            grid[i][j+1]='0';
            markall(grid,i,j+1);
        }

    
    }


    int numIslands(vector<vector<char>>& grid) {
        
        int ans=0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    markall(grid,i,j);

                }

            }

        }


        return ans;        
    }
};