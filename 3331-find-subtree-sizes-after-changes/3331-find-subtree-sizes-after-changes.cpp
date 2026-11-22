class Solution {
public:
    void getreqtree(const vector<vector<int>>& child, int cind,
                    const string& s, vector<int>& parent)
    {
        vector<int> closest(26, -1);
        vector<int> previous(parent.size());
        vector<pair<int, bool>> pending{{cind, false}};

        while (!pending.empty())
        {
            auto [node, leaving] = pending.back();
            pending.pop_back();

            int letter = s[node] - 'a';

            if (leaving)
            {
                closest[letter] = previous[node];
                continue;
            }

            previous[node] = closest[letter];

            if (closest[letter] != -1)
            {
                parent[node] = closest[letter];
            }

            closest[letter] = node;
            pending.emplace_back(node, true);

            for (int next : child[node])
            {
                pending.emplace_back(next, false);
            }
        }
    }

    int getSize(const vector<vector<int>>& child, int node, vector<int>& sizes)
    {
        vector<int> order{node};

        for (size_t i = 0; i < order.size(); i++)
        {
            for (int next : child[order[i]])
            {
                order.push_back(next);
            }
        }

        // Process children before their parents.
        for (auto it = order.rbegin(); it != order.rend(); ++it)
        {
            int current = *it;
            sizes[current] = 1;

            for (int next : child[current])
            {
                sizes[current] += sizes[next];
            }
        }

        return sizes[node];
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s)
    {
        vector<vector<int>> child(parent.size());

        for (int i = 0; i < parent.size(); i++)
        {
            int p = parent[i];

            if (p != -1)
            {
                child[p].push_back(i);
            }
        }

        getreqtree(child, 0, s, parent);

        child.clear();
        child.resize(parent.size());

        for (int i = 0; i < parent.size(); i++)
        {
            int p = parent[i];

            if (p != -1)
            {
                child[p].push_back(i);
            }
        }

        vector<int> sizes(parent.size());
        getSize(child, 0, sizes);
        parent.swap(sizes);

        return parent;
    }
};