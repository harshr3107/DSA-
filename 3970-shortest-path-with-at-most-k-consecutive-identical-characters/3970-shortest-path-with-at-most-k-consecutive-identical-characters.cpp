class compare {
public:
    bool operator()(const pair<int, pair<int, long long>>& a,
                    const pair<int, pair<int, long long>>& b) {
        return a.second.second > b.second.second;
    }
};

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adjlist(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adjlist[u].push_back({v, wt});
        }

        const long long INF = LLONG_MAX;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        priority_queue<
            pair<int, pair<int, long long>>,
            vector<pair<int, pair<int, long long>>>,
            compare
        > pq;

        dist[0][k] = 0;
        pq.push({0, {k, 0}});

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();

            int node = current.first;
            int kval = current.second.first;
            long long cost = current.second.second;

            // A better route to this exact state was found already.
            if (cost != dist[node][kval]) {
                continue;
            }

            if (kval == 0) {
                continue;
            }

            if (node == n - 1) {
                return static_cast<int>(cost);
            }

            for (auto& edge : adjlist[node]) {
                int nextNode = edge.first;
                int edgeWeight = edge.second;

                int nextK;
                if (labels[nextNode] == labels[node]) {
                    nextK = kval - 1;
                } else {
                    nextK = k;
                }

                long long nextCost = cost + edgeWeight;

                if (nextCost < dist[nextNode][nextK]) {
                    dist[nextNode][nextK] = nextCost;
                    pq.push({nextNode, {nextK, nextCost}});
                }
            }
        }

        return -1;
    }
};