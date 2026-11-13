class Solution {
public:
    void getdepth(TreeNode* root, int cdepth,
                  unordered_map<int, vector<TreeNode*>>& depth,
                  unordered_map<TreeNode*, TreeNode*>& parent,
                  unordered_map<TreeNode*, vector<TreeNode*>>& child)
    {
        if (root == nullptr)
        {
            return;
        }

        depth[cdepth].push_back(root);

        if (root->left != nullptr)
        {
            child[root].push_back(root->left);
            parent[root->left] = root;
        }

        if (root->right != nullptr)
        {
            child[root].push_back(root->right);
            parent[root->right] = root;
        }

        getdepth(root->left, cdepth + 1, depth, parent, child);
        getdepth(root->right, cdepth + 1, depth, parent, child);
    }

    void updatevalue(TreeNode* root, unordered_map<TreeNode*, int>& newvalue)
    {
        if (root == nullptr)
        {
            return;
        }

        root->val = newvalue.at(root);

        updatevalue(root->left, newvalue);
        updatevalue(root->right, newvalue);
    }

    TreeNode* replaceValueInTree(TreeNode* root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        unordered_map<int, vector<TreeNode*>> depth;
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, vector<TreeNode*>> child;
        unordered_map<TreeNode*, int> newvalue;

        getdepth(root, 0, depth, parent, child);
        newvalue[root] = 0;

        for (const auto& [level, nodes] : depth)
        {
            if (level == 0)
            {
                continue;
            }

            int sum = 0;
            for (TreeNode* node : nodes)
            {
                sum += node->val;
            }

            for (TreeNode* node : nodes)
            {
                TreeNode* p = parent.at(node);

                int rsum = 0;
                for (TreeNode* sibling : child.at(p))
                {
                    rsum += sibling->val;
                }

                newvalue[node] = sum - rsum;
            }
        }

        updatevalue(root, newvalue);
        return root;
    }
};