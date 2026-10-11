   
   
    class compare
    {

        public:

        bool operator()(vector<int>& a,vector<int>& b)
        {
            return a[0]>b[0];
        }
        


    };








class Solution {
public:
    

 

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        //bfs approch would work here

        priority_queue<vector<int>,vector<vector<int>>,compare> pq;
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),0));
         vector<vector<int>> visited(mat.size(),vector<int>(mat[0].size(),-1));

        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==0)
                {
                    vector<int> v;
                    visited[i][j]=1;
                    v.push_back(0);
                    v.push_back(i);
                    v.push_back(j);

                    pq.push(v);

                }

            }

        }

       



        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int val = it[0];
            int cr = it[1];
            int cc = it[2];

            if((cr-1)>=0 && visited[cr-1][cc]==-1 && mat[cr-1][cc]==1)
            {
                visited[cr-1][cc]=0;
                ans[cr-1][cc]=val+1;
                 vector<int> v;
                    v.push_back(val+1);
                    v.push_back(cr-1);
                    v.push_back(cc);

                    pq.push(v);

            }

            if((cr+1)<mat.size() && visited[cr+1][cc]==-1 && mat[cr+1][cc]==1)
            {
                visited[cr+1][cc]=0;
                ans[cr+1][cc]=val+1;
                 vector<int> v;
                    v.push_back(val+1);
                    v.push_back(cr+1);
                    v.push_back(cc);

                    pq.push(v);

            }


            if((cc-1)>=0 && visited[cr][cc-1]==-1 && mat[cr][cc-1]==1)
            {
                visited[cr][cc-1]=0;
                ans[cr][cc-1]=val+1;
                 vector<int> v;
                    v.push_back(val+1);
                    v.push_back(cr);
                    v.push_back(cc-1);

                    pq.push(v);

            }


            if((cc+1)<mat[0].size() && visited[cr][cc+1]==-1 && mat[cr][cc+1]==1)
            {
                visited[cr][cc+1]=0;
                ans[cr][cc+1]=val+1;
                 vector<int> v;
                    v.push_back(val+1);
                    v.push_back(cr);
                    v.push_back(cc+1);

                    pq.push(v);

            }



        }


        return ans;




        
    }
};