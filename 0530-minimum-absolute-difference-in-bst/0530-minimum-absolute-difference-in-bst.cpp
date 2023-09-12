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
     int ans=INT_MAX;
      TreeNode *prev=NULL;
     void solve(TreeNode *root){
            if(root==NULL)
                  return ;
            solve(root->left);
             if(prev!=NULL){
            ans=min(ans,abs(prev->val-root->val));
            prev=root;
             }
            else{
                prev=root;
            }
            solve(root->right);
         return ;
     }
public:
    int getMinimumDifference(TreeNode* root) {
         if(root==NULL)
               return 0;
          solve(root);
         return ans;
    }
};