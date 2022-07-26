/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { 
    private:
    TreeNode *solve(TreeNode *root,TreeNode *p,TreeNode *q)
    {
        if(root==NULL)
            return root; 
        if(root==p || root==q)
            return root;
        TreeNode *l=solve(root->left,p,q);
        TreeNode *r=solve(root->right,p,q);
        if(l==NULL) return r;
        else if(r==NULL) return l;
        else
            return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return root;
        return solve(root,p,q);
    }
};