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
    TreeNode *prev=NULL; 
    TreeNode *first=NULL;
    TreeNode *middle=NULL;
    TreeNode *last=NULL;
    void solve(TreeNode *root){
        if(root==NULL)
             return ;
        solve(root->left);
        if(prev==NULL){
            prev=root;
        }
        if(prev->val>root->val){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        solve(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
          if(root==NULL)
                return;
          solve(root);
          if(last!=NULL){
              if(last->val<first->val){
                  swap(last->val,first->val);
              }
              else{
                  swap(last->val,middle->val);
              }
          }
          else if(first!=NULL){
              swap(first->val,middle->val);
          }
        return ;
    }
};