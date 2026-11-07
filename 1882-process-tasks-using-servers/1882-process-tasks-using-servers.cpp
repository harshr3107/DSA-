class compare
{
    public:

    bool operator()(const pair<long long,int>& a,
                    const pair<long long,int>& b) const
    {
        if(a.first==b.first)
        {
            return a.second>b.second;
        }

        return a.first>b.first;
    }
};


class Solution {
public:

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       compare> pq;

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       compare> pq2;


        for(int i=0;i<servers.size();i++)
        {
            pq.push(make_pair(servers[i],i));
        }

        vector<int> ans(tasks.size(),0);
        long long ctime=0;

        for(int i=0;i<tasks.size();i++)
        {
            if(pq.empty())
            {
                auto it = pq2.top();
                long long cval = it.first;

                while(!pq2.empty() && pq2.top().first==cval)
                {
                    auto it=pq2.top();
                    pq.push(make_pair(servers[it.second],it.second));
                    pq2.pop();
                }

                ctime=cval;
            }

            ans[i]=pq.top().second;
            pq2.push(make_pair(ctime+tasks[i],ans[i]));
            pq.pop();
            if (ctime < (long long)i + 1)
            {
                ctime = (long long)i + 1;
            }

            while(!pq2.empty() && pq2.top().first<=ctime)
            {
                auto it = pq2.top();
                pq.push(make_pair(servers[it.second],it.second));
                pq2.pop();
            }
        }

        return ans;
    }
};