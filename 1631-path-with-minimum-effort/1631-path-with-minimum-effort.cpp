
class compare
{
    public:

    bool operator()(vector<int>& a,vector<int>& b)
    {
        return a[2]>b[2];
    }   

};






class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& height) {

            int i=0;
            int j=0;

        // vector<vector<bool>> visited(height.size(),vector<bool>(height[0].size(),false));

          priority_queue<vector<int>,vector<vector<int>>,compare> pq;
          vector<vector<int>> distance(height.size(),vector<int>(height[i].size(),INT_MAX));

          vector<int> v;
          v.push_back(0);
          v.push_back(0);
          v.push_back(0);


          pq.push(v);

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int i = it[0];
            int j = it[1];
            int cval=it[2];

            //cout<<"value of i j val is "<<i<<" "<<j<<" "<<cval<<endl;


            if(i==height.size()-1 && j==height[i].size()-1)
            {
                return cval;
            }


            if((i-1)>=0)
            {

                if(distance[i-1][j]>max(cval,abs(height[i][j]-height[i-1][j])))
                {
                    distance[i-1][j]=max(cval,abs(height[i][j]-height[i-1][j]));
                    v.clear();
                    v.push_back(i-1);
                    v.push_back(j);
                    v.push_back(distance[i-1][j]);
                    pq.push(v);
                }

            }

            if((i+1)<height.size())
            {

                 if(distance[i+1][j]>max(cval,abs(height[i][j]-height[i+1][j])))
                {
                    distance[i+1][j]=max(cval,abs(height[i][j]-height[i+1][j]));
                    v.clear();
                    v.push_back(i+1);
                    v.push_back(j);
                    v.push_back(distance[i+1][j]);
                    pq.push(v);
                }

            }

            if((j-1)>=0)
            {
                if(distance[i][j-1]>max(cval,abs(height[i][j]-height[i][j-1])))
                {
                    distance[i][j-1]=max(cval,abs(height[i][j]-height[i][j-1]));
                    v.clear();
                    v.push_back(i);
                    v.push_back(j-1);
                    v.push_back(distance[i][j-1]);
                    pq.push(v);
                }

            }

            if((j+1)<height[i].size())
            {

                if(distance[i][j+1]>max(cval,abs(height[i][j]-height[i][j+1])))
                {
                    distance[i][j+1]=max(cval,abs(height[i][j]-height[i][j+1]));
                    v.clear();
                    v.push_back(i);
                    v.push_back(j+1);
                    v.push_back(distance[i][j+1]);
                    pq.push(v);
                }


            }

        }


        return -1;




        
    }
};