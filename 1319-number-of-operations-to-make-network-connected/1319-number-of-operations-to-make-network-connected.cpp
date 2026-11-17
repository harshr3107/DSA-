class Solution {
public:

     void dfs(vector<vector<int>>& adjlist,int i,vector<bool>& visited)
     {
        visited[i]=true;

        for(auto it: adjlist[i])
        {
            if(visited[it]==false)
            {
                dfs(adjlist,it,visited);
            }

        }

     }


    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1)
        {
            return -1;
        }

        //it can be done using 

        vector<vector<int>> adjlist(n+1);

        for(auto it: connections)
        {
            int u = it[0];
            int v = it[1];

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);



        }


        vector<bool> visited(n,false);
        int component=0;

        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                dfs(adjlist,i,visited);
                component++;
            }

        }

        cout<<"number of total components is "<<component<<endl;

        return component-1;
        


        
    }
};