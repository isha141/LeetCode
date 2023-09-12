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
     bool solve(TreeNode *left,TreeNode *right){
          if(left==NULL)
              return right==NULL;
          if(right==NULL)
                return left==NULL;
         if(left->val!=right->val)
               return 0;
         bool l=solve(left->right,right->left);
         bool r=solve(left->left,right->right);
          return (l && r);
     }
public:
    bool isSymmetric(TreeNode* root) {
         return solve(root->left,root->right);
    }
};