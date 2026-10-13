class Solution {
public:

   bool checkbipi(vector<vector<int>>& graph,int i,vector<bool>& visited,vector<int>& color)
   {
     
     visited[i]=true;
     int ccol = color[i];

     for(auto it: graph[i])
     {
        if(visited[it]==false)
        {
            color[it]=ccol==0?1:0;
            visited[it]=true;
            if(checkbipi(graph,it,visited,color)==false)
            {
                return false;
            }

        }else if(color[it]==ccol)
        {
            return false;
        }

     }

     return true;
       

   }


    bool isBipartite(vector<vector<int>>& graph) {


        //bipatrite graph is not cyclic at all 

        //we beed to assign color and bipatrite makes sure that no two edges have same color adjacent to one another


        vector<bool> visited(graph.size(),false);
        vector<int> color(graph.size(),-1);

        
       for(int i=0;i<graph.size();i++)
        {
            if(visited[i]==false)
            {
                color[i]=0;

                if(checkbipi(graph,i,visited,color)==false)
                {
                    return false;
                }
            }
        }

     return true;
        
    }
};