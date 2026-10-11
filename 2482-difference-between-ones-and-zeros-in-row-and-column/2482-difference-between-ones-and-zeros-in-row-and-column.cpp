class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {

        //calclate 0 seprately for rows 

        vector<int> zerorow(grid.size(),0);

        for(int i=0;i<grid.size();i++)
        {
            int a=0;
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==0)
                {
                    a++;
                }

            }

            zerorow[i]=a;

        }


        //calculate zero seprately for col
        vector<int> zerocol(grid[0].size(),0);

        for(int j=0;j<grid[0].size();j++)
        {
             int a=0;
            for(int i=0;i<grid.size();i++)
            {

                if(grid[i][j]==0)
                {
                    a++;
                }

            }

            zerocol[j]=a;

        }

       



        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                int onesr = grid.size()-zerorow[i];
                int onec = grid[0].size()-zerocol[j];

                

                grid[i][j]=onesr+onec-zerorow[i]-zerocol[j];

            }

        }

        return grid;



        
    }
};