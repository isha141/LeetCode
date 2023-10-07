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
    int solve(TreeNode *root){
          if(root==NULL)
                return 0;
          int l=solve(root->left);
          int r=solve(root->right);
           if(l==-1 || r==-1){
               return -1;
           }
           if(abs(l-r)>1)
                 return -1;
          return max(l,r)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
          if(root==NULL)
                return 1;
          int ans=solve(root);
          if(ans==-1)
                return 0;
          return 1;
    }
};