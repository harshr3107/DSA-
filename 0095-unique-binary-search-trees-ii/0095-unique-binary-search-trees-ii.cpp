class Solution {
public:
    vector<TreeNode*> getall(int start, int end) {
        if (start > end) {
            return {nullptr};
        }

        vector<TreeNode*> results;

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = getall(start, i - 1);
            vector<TreeNode*> rightTrees = getall(i + 1, end);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    results.push_back(root);
                }
            }
        }

        return results;
    }

    vector<TreeNode*> generateTrees(int n) {
        return getall(1, n);
    }
};