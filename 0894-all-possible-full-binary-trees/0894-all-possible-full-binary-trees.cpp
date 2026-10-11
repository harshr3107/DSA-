/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<TreeNode*> getall(int n)
    {
        if((n&1)==0)
        {
            return {};
        }

        if(n==1)
        {
            TreeNode* root = new TreeNode(0);
            return {root};
        }

        vector<TreeNode*> result;
        for(int i=1;i<n;i+=2)
        {
            vector<TreeNode*> l = getall(i);
            vector<TreeNode*> r = getall(n-i-1);


            for(auto it: l)
            {
                for(auto it2: r)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = it;
                    root->right=it2;

                    result.push_back(root);

                }
            }

        }

        return result;


    }


    vector<TreeNode*> allPossibleFBT(int n) {


        return getall(n);
        
    }
};