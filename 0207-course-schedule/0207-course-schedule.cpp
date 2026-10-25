class Solution {
public:
   

   //checkcycle(adjlist,i,visited)


   bool checkcycle(vector<vector<int>>& adjlist,int i,vector<bool>& visited,vector<bool>& pathvisited)
   {
        visited[i]=true;
        pathvisited[i]=true;

        for(auto it: adjlist[i])
        {
            if(visited[it]==false)
            {
                if(checkcycle(adjlist,it,visited,pathvisited)==true)
                {
                    return true;
                }
            }else{

                if(pathvisited[it]==true)
                {
                    return true;
                }


            }


        }

        pathvisited[i]=false;


        return false;

   }



    bool canFinish(int n, vector<vector<int>>& prerequisites) {


        vector<vector<int>> adjlist(n);

        //so yes this is done 

        for(auto it: prerequisites)
        {
            int u = it[0];
            int v = it[1];

            adjlist[v].push_back(u);

        }

        //detectcycle

        vector<bool> visited(n,false);
         vector<bool> pathvisited(n,false);

        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                if(checkcycle(adjlist,i,visited,pathvisited)==true)
                {
                    return false;
                }
            }

        }


        return true;


        
    }
};