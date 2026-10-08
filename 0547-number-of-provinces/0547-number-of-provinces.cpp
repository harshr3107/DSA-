class Solution {
public:
    

    void getall(vector<vector<int>>& adjlist,int i,vector<int>& visited)
    {
        visited[i]=true;

        for(auto it: adjlist[i])
        {
            if(visited[it]==false)
            {
                getall(adjlist,it,visited);
            }

        }

    }





    int findCircleNum(vector<vector<int>>& con) {
        
        vector<vector<int>> adjlist(con.size());


        for(int i=0;i<con.size();i++)
        {
            for(int j=0;j<con[i].size();j++)
            {
                if(con[i][j]==1)
                {
                    adjlist[i].push_back(j);

                }

            }
        }


        vector<int> visited(con.size());
        int province=0;

        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==false)
            {
                province++;
                getall(adjlist,i,visited);

            }

        }


        return province;





    }
};