class Solution {
public:
    unordered_map<char, int> getans(vector<vector<int>>& adjlist, int src,string& labels,vector<bool>& visited,vector<int>& ans) 
    {
        visited[src] = true;

        unordered_map<char, int> track;

        // Include this node in its subtree's label counts.
        track[labels[src]]++;

        for (auto it : adjlist[src]) {
            if (visited[it] == false) {
                unordered_map<char, int> child =
                    getans(adjlist, it, labels, visited, ans);

                // Add all counts from the child's subtree.
                for (auto entry : child) {
                    track[entry.first] += entry.second;
                }
            }
        }

        // Count of this node's label across its whole subtree.
        ans[src] = track[labels[src]];

        return track;
    }

    vector<int> countSubTrees(
        int n,
        vector<vector<int>>& edges,
        string labels
    ) {
        vector<vector<int>> adjlist(n);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        vector<int> ans(n, 0);
        vector<bool> visited(n, false);

        getans(adjlist, 0, labels, visited, ans);

        return ans;
    }
};