class Solution {
public:
    

    //getans(grid,i,j,visited,total);

    int getans(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& visited,int total)
    {
        cout<<"the current value of i and j is "<<i<<" "<<j<<endl;
        


        if(grid[i][j]==2)
        {
            //cout<<"i entered here the value of total is "<<total<<endl;

            if(total==1)
            {
                return 1;
            }

            return 0;
        }

        int ans=0;
        visited[i][j]=true;

        if((i+1)<grid.size() && grid[i+1][j]!=-1 && visited[i+1][j]==false)
        {
                ans=ans+getans(grid,i+1,j,visited,total-1);
        }

        if((i-1)>=0 && grid[i-1][j]!=-1 && visited[i-1][j]==false)
        {
                ans=ans+getans(grid,i-1,j,visited,total-1);
        }

        if((j+1)<grid[i].size() && grid[i][j+1]!=-1 && visited[i][j+1]==false)
        {
                ans=ans+getans(grid,i,j+1,visited,total-1);
        }

        if((j-1)>=0 && grid[i][j-1]!=-1 && visited[i][j-1]==false)
        {
                ans=ans+getans(grid,i,j-1,visited,total-1);
        }

        visited[i][j]=false;

        return ans;

    



    }




    int uniquePathsIII(vector<vector<int>>& grid) {

        

        //count obstacles

        int obs=0;
        pair<int,int> temp;
        pair<int,int>  esquare;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                

                if(grid[i][j]==-1)
                {
                    obs++;
                }else if(grid[i][j]==1)
                {
                    temp=make_pair(i,j);
                }

            }

        }

        int n = grid.size();
        int m = grid[0].size();

        int total=(m*n)-obs;

        //cout<<"initially number of cells we ned topass is "<<total<<endl;

        int i = temp.first;
        int j = temp.second;
       vector<vector<bool>> visited(n, vector<bool>(m, false));
       return getans(grid, i, j, visited, total);
        



        
    }
};