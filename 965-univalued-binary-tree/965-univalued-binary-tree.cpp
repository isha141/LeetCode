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
    bool  solve(TreeNode *root,int temp)
    {
        if(root==NULL)
            return 1;
        if(root->val!=temp)
            return 0;
        bool l=solve(root->left,temp);
        bool r=solve(root->right,temp);
        return (l && r);
    }
public:
    bool isUnivalTree(TreeNode* root) { 
        if(root==NULL)
            return 0;
        int temp=root->val;
        return solve(root,temp);
    }
};