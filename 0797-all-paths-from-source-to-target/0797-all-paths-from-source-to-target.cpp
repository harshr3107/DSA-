class Solution {
public:

    
    void getpath(vector<vector<int>>& graph,int i,int dest,vector<int> cpath,vector<vector<int>>& ans,vector<bool>
    & visited)
    {

        if(i==dest)
        {
            ans.push_back(cpath);
        }

       // visited[i]=true;



        for(auto it: graph[i])
        {
            
                cpath.push_back(it);
                getpath(graph,it,dest,cpath,ans,visited);
                cpath.pop_back();
            
        }

        

        

        



    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

            int n = graph.size();
            vector<int> cpath;
            vector<vector<int>> ans;
            vector<bool> visited(n+1,false);
            int i=0;
            cpath.push_back(0);


          getpath(graph,i,n-1,cpath,ans,visited);

          return ans;
    }
};