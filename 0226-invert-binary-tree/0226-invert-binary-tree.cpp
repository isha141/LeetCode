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
    TreeNode *solve(TreeNode *root){
        if(root==NULL)
             return root;
        TreeNode *l=solve(root->left);
        TreeNode *r=solve(root->right); 
        if(root!=NULL){
            root->right=l;
            root->left=r;
        }
        return root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
         if(root==NULL)
               return root;
         return solve(root);
    }
};