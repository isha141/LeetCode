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
    TreeNode *prev=NULL;
    TreeNode *solve(TreeNode *root)
    {
        if(root==NULL) return NULL; 
        solve(root->right);
        solve(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root; 
        return root;
    }
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return ;
        solve(root);
    }
};