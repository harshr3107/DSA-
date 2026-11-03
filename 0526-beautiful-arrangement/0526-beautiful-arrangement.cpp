class Solution {
public:
    int getallways(int n,int i,vector<bool>& visited)
    {
        if(i==n+1)
        {
            return 1;
        }

        int ways=0;

        for(int j=1;j<=n;j++)
        {
            if(visited[j]==true)
            {
                continue;
            }




            if((i%j)==0 || (j%i)==0)
            {
                visited[j]=true;
                ways+=(getallways(n,i+1,visited));
                visited[j]=false;
            }

        

        }

        return ways;

    }


    int countArrangement(int n) {

        vector<bool> visited(n+1,false);
        int i=1;
        return getallways(n,i,visited);
        
    }
};