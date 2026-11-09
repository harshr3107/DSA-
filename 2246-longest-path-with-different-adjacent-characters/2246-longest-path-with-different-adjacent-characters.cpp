
class compare
{

    public:

    bool operator()(int& a,int& b)
    {
        return a>b;
    }

};








class Solution {
public:
    // getlongestpath(children,0);

    pair<char,int> getlongestpath(vector<vector<int>>& children,int src,vector<bool>& visited,string& s,int& ans)
    {

        visited[src]=true;

        if(children[src].size()==0)
        {
            return make_pair(s.at(src),1);
        }


        vector<pair<char,int>> v;


        for(auto it: children[src])
        {
            if(visited[it]==false)
            {
                pair<char,int> temp = getlongestpath(children,it,visited,s,ans);
                v.push_back(temp);
            }

        }

        //we know the value of m by this method
        int m=0;
        priority_queue<int,vector<int>,compare> pq;

        

       // cout<<"i am at the source "<<src<<endl;
        for(auto it: v)
        {
            

            char a = it.first;
            int h = it.second;

            //cout<<a<<" "<<h<<endl;

            if(a!=s.at(src))
            {
                //cout<<"i came here inside\n";
                

                 m = max(m, h);

                    pq.push(h);
                    if (pq.size() > 2)
                    {
                        pq.pop();
                    }

            }
        }



        

        int l=0;
        if(pq.size()==2)
        {
            l=pq.top();
            pq.pop();
            l+=pq.top();
            pq.pop();
        }

        ans=max(ans,max(m+1,l+1));

        return make_pair(s.at(src),m+1);


            

    }



    int longestPath(vector<int>& parent, string s) {

        //let me create children wala part

        vector<vector<int>> children(s.length());


        for(int i=0;i<parent.size();i++)
        {

            if(parent[i]!=-1)
            {
                children[parent[i]].push_back(i);
            }
    
        }

        int ans=1;
        vector<bool> visited(parent.size(),false);
        int prev=-1;

        getlongestpath(children,0,visited,s,ans);

        return ans;
        
    }
};