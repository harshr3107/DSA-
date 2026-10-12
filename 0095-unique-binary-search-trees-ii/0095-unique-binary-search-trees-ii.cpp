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
   
   vector<TreeNode*> gettree(int start,int end)
   {
       if(start>end)
       {
        return {nullptr};
       }


       vector<TreeNode*> result;


       for(int i=start;i<=end;i++)
       {
          
          vector<TreeNode*> l = gettree(start,i-1);
          vector<TreeNode*> r = gettree(i+1,end);

          for(auto it: l)
          {
            for(auto it2: r)
            {
                TreeNode* root = new TreeNode(i);

                root->left=it;
                root->right=it2;

                result.push_back(root);
            }



          }

       }


       return result;


   }


    vector<TreeNode*> generateTrees(int n) {

        int start=1;
        int end=n;

        return gettree(start,end);


        
    }
};