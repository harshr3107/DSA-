class Solution {
public:
   //markall(land,i,j,temp)

   void markall(vector<vector<int>>& land,int i,int j,pair<int,int>& temp)
   {

       int x = temp.first;
       
       if(i>=x)
       {
          int y = temp.second;

          if(j>=y)
          {
             temp = make_pair(i,j);
          }

       }



      /*if((i-1)>=0 && land[i-1][j]==1)
      {
           land[i-1][j]=0;
           markall(land,i-1,j,temp);

      }*/

      if((i+1)<land.size() && land[i+1][j]==1)
      {
        land[i+1][j]=0;
        markall(land,i+1,j,temp);
      }

      /*if((j-1)>=0 && land[i][j-1]==1)
      {
           land[i][j-1]=0;
           markall(land,i,j-1,temp);

      }*/


      if((j+1)<land[i].size() && land[i][j+1]==1)
      {
           land[i][j+1]=0;
           markall(land,i,j+1,temp);

      }
        

   }


    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

        vector<vector<int>> ans;

        for(int i=0;i<land.size();i++)
        {
            for(int j=0;j<land[i].size();j++)
            {
                if(land[i][j]==1)
                {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);

                    pair<int,int> temp = make_pair(i,j);

                    markall(land,i,j,temp);

                    v.push_back(temp.first);
                    v.push_back(temp.second);

                    ans.push_back(v);


                }

            }

        }

        return ans;
        
    }
};