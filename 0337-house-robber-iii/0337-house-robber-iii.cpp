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
    

    int getans(TreeNode* root,map<TreeNode*,int>& dp)
    {

        if(root==NULL)
        {
            return 0;
        }


        if(dp.find(root)!=dp.end())
        {
            return dp[root];
        }

        //
        int take=root->val;
        int nottake=0;

        //either we take up this root

        if(root->left!=NULL)
        { 

         take=take+getans(root->left->left,dp)+getans(root->left->right,dp);

        }

        if(root->right!=NULL)
        {
            take=take+getans(root->right->left,dp)+getans(root->right->right,dp);

        }

        nottake = getans(root->left,dp)+getans(root->right,dp);


        return dp[root]=max(take,nottake);




    }
  

    int rob(TreeNode* root) {

        map<TreeNode*,int> dp;
        return getans(root,dp);
        
        
    }
};