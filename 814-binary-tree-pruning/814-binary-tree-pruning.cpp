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
    TreeNode *solve(TreeNode *root,bool flag){
        if(root==NULL)
            return NULL;
        root->left=solve(root->left ,0); 
        root->right=solve(root->right,0);
        if(root->val==0 && !root->left && !root->right)
            return NULL; 
        return root;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL)
            return NULL; 
        bool flag=0;
        return solve(root,flag);
    }
};