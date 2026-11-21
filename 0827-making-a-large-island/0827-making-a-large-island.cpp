class Solution {
public:


    int getparent(vector<int>& parent,int node)
    {
        if(parent[node]==node)
        {
            return node;
        }

        return parent[node]=getparent(parent,parent[node]);

    }
    
    void unionbysize(int u,int v,vector<int>& parent,vector<int>& size)
    {
        int pu = getparent(parent,u);
        int pv = getparent(parent,v);

        if(pu==pv)
        {
            return;
        }

        if(size[pu]>size[pv])
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }

    }

    bool isvalid(int i,int j,int n)
    {

        if(i<0 || j<0 || i>=n || j>=n)
        {
            return false;
        }

        return true;

    }


    int largestIsland(vector<vector<int>>& grid) {


        int n = grid.size();
        int total = n*n;

        vector<int> parent(total);
        vector<int> size(total,1);

        for(int i=0;i<total;i++)
        {
            parent[i]=i;
        }


        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {


                if(grid[i][j]==1)
                {
                    int cnode = n*i+j;


                    if(isvalid(i-1,j,n) && grid[i-1][j]==1)
                    {
                        int tnode = n*(i-1)+j;

                        unionbysize(cnode,tnode,parent,size);


                    }

                    if(isvalid(i+1,j,n) && grid[i+1][j]==1)
                    {
                        int tnode = n*(i+1)+j;

                        unionbysize(cnode,tnode,parent,size);


                    }

                    if(isvalid(i,j-1,n) && grid[i][j-1]==1)
                    {
                        int tnode = n*i+(j-1);

                        unionbysize(cnode,tnode,parent,size);


                    }

                    if(isvalid(i,j+1,n) && grid[i][j+1]==1)
                    {
                        int tnode = n*i+(j+1);

                        unionbysize(cnode,tnode,parent,size);


                    }






                }




            }

        }

        int maxi = *max_element(size.begin(),size.end());

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                
                unordered_set<int> st;

                if(grid[i][j]==0)
                {

                    int cnode = n*i+j;


                    if(isvalid(i-1,j,n) && grid[i-1][j]==1)
                    {
                        int tnode = n*(i-1)+j;
                        st.insert(getparent(parent,tnode));


                        

                    }

                    if(isvalid(i+1,j,n) && grid[i+1][j]==1)
                    {
                        int tnode = n*(i+1)+j;
                        st.insert(getparent(parent,tnode));

                        


                    }

                    if(isvalid(i,j-1,n) && grid[i][j-1]==1)
                    {
                        int tnode = n*i+(j-1);
                        st.insert(getparent(parent,tnode));

                       


                    }

                    if(isvalid(i,j+1,n) && grid[i][j+1]==1)
                    {
                        int tnode = n*i+(j+1);
                        st.insert(getparent(parent,tnode));

                    }









                }

                int a=1;
                for(auto it: st)
                {
                    a+=size[it];
                }

                maxi=max(maxi,a);




            }

        }

        return maxi;



        
    }
};