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


        vector<TreeNode*> ans;


        for(int i=1;i<n;i+=2)
        {
            vector<TreeNode*> left = getall(i);
            vector<TreeNode*> right = getall(n-i-1);

            

            for(auto it : left)
            {
                for(auto it2 : right)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left=it;
                    root->right=it2;
                    ans.push_back(root);
                }
            }



        }

        return ans;


    }

    vector<TreeNode*> allPossibleFBT(int n) {

        return getall(n);
        
    }
};