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
            return NULL; 
    TreeNode *lefti=root->left; 
               TreeNode *righti=root->right;
        root->right=solve(lefti);
         root->left=solve(righti);
        return root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
         solve(root);
        return root;
    }
};