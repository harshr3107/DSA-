class Solution {
public:
    vector<TreeNode*> getallpossible(int n) {
        if (n % 2 == 0) {
            return {};
        }

        if (n == 1) {
            return {new TreeNode(0)};
        }

        vector<TreeNode*> ans;

        // The root uses 1 node, leaving n - 1 nodes for both subtrees.
        for (int leftSize = 1; leftSize < n; leftSize += 2) {
            int rightSize = n - 1 - leftSize;

            vector<TreeNode*> lefty = getallpossible(leftSize);
            vector<TreeNode*> righty = getallpossible(rightSize);

            for (auto it : lefty) {
                for (auto it2 : righty) {
                    TreeNode* root = new TreeNode(0);
                    root->left = it;
                    root->right = it2;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        return getallpossible(n);
    }
};