class Solution {
public:
    

    static bool compare(vector<int>& a,vector<int>& b)
    {
        return a[1]<b[1];
    }

    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(),logs.end(),compare);

        vector<pair<int,int>> q;

        for(int i=0;i<queries.size();i++)
        {
            q.push_back(make_pair(queries[i],i));
        }

        sort(q.begin(),q.end());

        int left=0;
        int right=0;
        vector<int> servercount(n+1,0);
        int activeserver=0;

        vector<int> ans(queries.size(),0);


        for(auto it: q)
        {
            int time = it.first;
            int index = it.second;

            while(right<logs.size() && logs[right][1]<=time)
            {
                int server = logs[right][0];

                if(servercount[server]==0)
                {
                    activeserver++;
                }

                servercount[server]++;
                right++;
            }


            while(left<right && logs[left][1]<time-x)
            {
                int server = logs[left][0];

                servercount[server]--;
                if(servercount[server]==0)
                {
                    activeserver--;
                }

                
                left++;

            }

            ans[index]=n-activeserver;


            



        }

        return ans;
        
    }
};