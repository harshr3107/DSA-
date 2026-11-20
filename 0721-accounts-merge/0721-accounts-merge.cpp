class Solution {
public:

    int getparent(vector<int>& parent,int a)
    {
        if(parent[a]==a)
        {
            return parent[a];
        }

        return parent[a]=getparent(parent,parent[a]);

    }

    
    void unionbysize(int u ,int v, vector<int>& parent,vector<int>& size)
    {
        int pu = getparent(parent,u);
        int pv = getparent(parent,v);

        if(pu==pv)
        {
            return;
        }

        if(size[pv]>size[pu])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }

    }




    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        vector<int> parent(accounts.size());
        vector<int> size(accounts.size(),1);

        for(int i=0;i<parent.size();i++)
        {
            parent[i]=i;
        }

        map<string,int> mp;

        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j])==mp.end())
                {

                    mp[accounts[i][j]]=i;

                }else{

                    unionbysize(mp[accounts[i][j]],i,parent,size);    

                }

            }

        }


       
        int n = accounts.size();
        vector<vector<string>> ans(n);

        for(auto it : mp)
        {
            int root = getparent(parent, it.second);
            ans[root].push_back(it.first);
        }

        vector<vector<string>> result;

        for(int i = 0; i < n; i++)
        {
            if(ans[i].size() > 0)
            {
                ans[i].insert(ans[i].begin(), accounts[i][0]);
                result.push_back(ans[i]);
            }
        }

        return result;




        
        
    }
};