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
    TreeNode *ans=NULL;
    bool solve(TreeNode *root,int val){
          if(root==NULL)
                return 0;
          if(root->val==val){
              ans=root;
                return 1;
          }
          if(root->val<val){
              if(solve(root->right,val))
                   return 1;
          }
          else if(root->val>=val){
                if(solve(root->left,val))
                      return 1;
          }
        return 0;
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
          if(root==NULL)
                return root;
          solve(root,val);
          return ans;
    }
};