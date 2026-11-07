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
    

    int getans(TreeNode* root,int& ans)
    {
        if(root==NULL)
        {
            return 0;
        }

        if(root->left==NULL && root->right==NULL)
        {
            return 1;
        }


        int left=getans(root->left,ans);
        int right=getans(root->right,ans);

        int lefty=0;
        int righty=0;

        if(root->left!=NULL && root->val==root->left->val)
        {
            lefty=left;
        }

        if(root->right!=NULL && root->val==root->right->val)
        {
            righty=right;
        }

        ans=max(ans,1+lefty+righty);

        return 1+max(lefty,righty);


    }



    int longestUnivaluePath(TreeNode* root) {
        
        int ans=0;
        getans(root,ans);

        return ans==0?0:ans-1;
        
    }
};