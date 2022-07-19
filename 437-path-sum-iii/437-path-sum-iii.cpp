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
    int solve(TreeNode *root,long long  target)
    {
        if(!root) return 0;
            
    return (target==root->val) + solve(root->left,target - root->val)
        + solve(root->right,target - root->val);
    }
public:
    int pathSum(TreeNode* root, int target) {
        if(root==NULL)
            return 0;
        return solve(root,(long long)target) + pathSum(root->left ,target) + pathSum(root->right ,target);
    }
};
