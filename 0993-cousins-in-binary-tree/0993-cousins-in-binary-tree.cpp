class Solution {
public:
    void getdepth(TreeNode* root, int x, int y, int depth,
                  int& ans1, int& ans2, map<int, int>& parent)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->val == x)
        {
            ans1 = depth;
        }

        if (root->val == y)
        {
            ans2 = depth;
        }

        if (root->left != nullptr)
        {
            parent[root->left->val] = root->val;
        }

        if (root->right != nullptr)
        {
            parent[root->right->val] = root->val;
        }

        getdepth(root->left, x, y, depth + 1, ans1, ans2, parent);
        getdepth(root->right, x, y, depth + 1, ans1, ans2, parent);
    }

    bool isCousins(TreeNode* root, int x, int y)
    {
        int ans1 = -1;
        int ans2 = -1;
        map<int, int> parent;

        getdepth(root, x, y, 0, ans1, ans2, parent);

        return ans1 > 0 && ans1 == ans2 && parent[x] != parent[y];
    }
};