class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        int i=grid.size()-1;
        int j=0;


        bool up=true;


        while(j<grid[0].size())
        {
            //cout<<"value of i and j is "<<i<<" "<<j<<endl;

            int tempx;
            int tempy;

            if(up)
            {
            tempx = i;
            tempy = 0;
            }else{

                tempx=0;
                tempy=j;


            }


            vector<int> v;

            while(tempx<grid.size() && tempy<grid[0].size())
            {
                v.push_back(grid[tempx][tempy]);
                tempx++;
                tempy++;
            }

            if(up==false)
            {
               sort(v.begin(),v.end());
            }else{
                  sort(v.begin(),v.end(),greater<int>());
            }

            if(up)
            {
            tempx = i;
            tempy = 0;
            }else{

                tempx=0;
                tempy=j;


            }
            int l=0;

            while(tempx<grid.size() && tempy<grid[0].size())
            {
                grid[tempx][tempy]=v[l];
                tempx++;
                tempy++;
                l++;
            }


            
            if(i==0 && up==true)
            {
                j=1;
                up=false;
                continue;
            }
            i--;

            if(up==false)
            {
                i=0;
                j++;
            }






        }


        return grid;
        
    }
};