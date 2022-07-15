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
    int height(TreeNode *root){
        if(root==NULL) return 0;
        int l=height(root->left)+1;
        int r=height(root->right)+1;
        return max(l,r);
    }
    private:
    bool solve(TreeNode *root){
        if(root==NULL)
            return 1;
        int l=height(root->left);
        int r=height(root->right);
        if(abs(l-r)>1)
            return 0;
        if(solve(root->left)==0)
            return 0;
        if(solve(root->right)==0) 
            return 0;
        else
            return 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return 1;
        return solve(root);
    }
};