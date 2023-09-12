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
    private:
    bool solve(TreeNode *root,int target,int sum){
           if(root==NULL)
                 return 0;
          if(root->left==NULL && root->right==NULL){
              if(sum+root->val==target)
                    return 1;
              return 0;
          } 
         bool l=solve(root->left,target,sum+root->val);
         bool r=solve(root->right,target,sum+root->val);
          return (l || r);
    }
public:
    bool hasPathSum(TreeNode* root, int target) {
         if(root==NULL)
               return 0;
         return solve(root, target,0);
    }
};