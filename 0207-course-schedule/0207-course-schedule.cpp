class Solution {
public:
   

   bool dfs(vector<vector<int>>& adjlist,int i,vector<bool>& visited,vector<bool>& pathvisited)
   {

         visited[i]=true;
         pathvisited[i]=true;

         for(auto it: adjlist[i])
         {
            if(visited[it]==false)
            {
                if(dfs(adjlist,it,visited,pathvisited))
                {
                    return true;
                }

            }else if(pathvisited[it]==true)
            {
                return true;
            }

         }

         pathvisited[i]=false;

         return false;
         

   }



    bool canFinish(int n, vector<vector<int>>& pre) {

        vector<vector<int>> adjlist(n);

        for(int i=0;i<pre.size();i++)
        {
            for(int j=0;j<pre[i].size();j++)
            {
                int u = pre[i][0];
                int v = pre[i][1];

                adjlist[u].push_back(v);

            }

        }



        //dfs method 

        vector<bool> visited(n,false);
        vector<bool> pathvisited(n,false);

        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==false)
            {
                if(dfs(adjlist,i,visited,pathvisited)==true)
                {
                    return false;
                }
            }

        }

        return true;
        
    }
};