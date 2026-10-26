class Solution {
public:
    

    int getans(vector<vector<int>>& grid,int i,int j,int k)
    {

        if(i==grid.size() || j==grid[0].size() || i==-1 || j==-1)
        {
            return 0;
        }

        long long ans=grid[i][j];
        grid[i][j]=0;

        if((i-1)>=0 && grid[i-1][j]!=0)
        {

            ans=(ans+getans(grid,i-1,j,k))%k;
        }

        if((i+1)<grid.size() && grid[i+1][j]!=0)
        {
            ans=(ans+getans(grid,i+1,j,k))%k;
        }

        if((j+1)<grid[0].size() && grid[i][j+1]!=0)
        {
            ans=(ans+getans(grid,i,j+1,k))%k;
        }

        if((j-1)>=0 && grid[i][j-1]!=0)
        {
            ans=(ans+getans(grid,i,j-1,k))%k;
        }

        return ans;


    }


    int countIslands(vector<vector<int>>& grid, int k) {


       
        int ans=0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]!=0)
                {
                    //cout<<"i entered here for "<<i<<" "<<j<<endl;
                    int a = getans(grid,i,j,k);
                    //cout<<"the first island the sum is "<<a<<endl;
                    if((a%k)==0)
                    {
                        ans+=1;
                    }

                }
            }

        }



        return ans;
        
    }
};