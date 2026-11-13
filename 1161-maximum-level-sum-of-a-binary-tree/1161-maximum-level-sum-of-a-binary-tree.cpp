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
    int maxLevelSum(TreeNode* root) {

        int i=0;
         queue<TreeNode*> q;
         q.push(root);
         int level=1;
         int msum=INT_MIN;
         int ans=1;

         while(!q.empty())
         {

           

            int size = q.size();
            int csum=0;

            for(int i=0;i<size;i++)
            {
                 auto it = q.front();
                 q.pop();
                 csum+=it->val;

                 if(it->left!=NULL)
                 {
                    q.push(it->left);
                 }

                 if(it->right!=NULL)
                 {
                    q.push(it->right);
                 }
                

            }


            if(csum>msum)
            {
                msum=csum;
                ans=level;
            }

            level++;

         }


         return ans;




        
    }
};