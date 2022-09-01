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
    int maxi=0;
    int fun(TreeNode *root,int temp)
    {
        if(root==NULL)
            return 0;
        if(root->val!=temp)
            return 0;
        int l=fun(root->left,temp)+1;
        int r=fun(root->right,temp)+1;
        return max(l,r);
        
    }
    int solve(TreeNode *root)
    {
        
        if(root==NULL) 
            return 0;
        int l=fun(root->left,root->val);
        int r=fun(root->right,root->val);
        maxi=max(maxi,(l+r));
        solve(root->left);
        solve(root->right);
         return 0;   
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL)
            return 0;
        solve(root);
        return maxi;
    }
};