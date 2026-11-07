/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    map<long long, int> getans(TreeNode* root, int targetsum, int& ans)
    {
        if (root == NULL)
        {
            return {};
        }

        if (root->left == NULL && root->right == NULL)
        {
            map<long long, int> mp;
            mp[root->val] = 1;

            if (targetsum == root->val)
            {
                ans += 1;
            }
            return mp;
        }

        map<long long, int> left =
            getans(root->left, targetsum, ans);
        map<long long, int> right =
            getans(root->right, targetsum, ans);

        if (targetsum == root->val)
        {
            ans += 1;
        }

        long long req = (long long)targetsum - root->val;

        // Check paths starting at this node and continuing into a child.
        ans += left[req];
        ans += right[req];

        map<long long, int> mp;

        for (auto it : left)
        {
            mp[it.first + root->val] += it.second;
        }

        for (auto it : right)
        {
            mp[it.first + root->val] += it.second;
        }

        mp[root->val] += 1;

        return mp;
    }

    int pathSum(TreeNode* root, int targetsum)
    {
        int ans = 0;
        getans(root, targetsum, ans);
        return ans;
    }
};