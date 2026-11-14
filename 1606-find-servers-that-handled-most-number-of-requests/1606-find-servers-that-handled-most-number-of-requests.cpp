class compare
{
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
    {
        if (a.second == b.second)
        {
            return a.first > b.first;
        }

        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        set<int> available;
        unordered_map<int, int> count;
        int answer = 0;

        for (int server = 0; server < k; server++)
        {
            available.insert(server);
        }

        for (int i = 0; i < arrival.size(); i++)
        {
            int ctime = arrival[i];

            while (!pq.empty() && pq.top().second <= ctime)
            {
                available.insert(pq.top().first);
                pq.pop();
            }

            if (available.empty())
            {
                continue;
            }

            int reqserver = i % k;
            auto it = available.lower_bound(reqserver);

            if (it == available.end())
            {
                it = available.begin();
            }

            int server = *it;
            available.erase(it);

            pq.push(make_pair(server, ctime + load[i]));
            count[server]++;
            answer = max(answer, count[server]);
        }

        vector<int> ans;

        for (const auto& it : count)
        {
            if (it.second == answer)
            {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};