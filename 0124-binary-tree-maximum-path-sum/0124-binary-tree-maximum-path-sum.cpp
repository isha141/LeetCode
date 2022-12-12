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
    int ans=INT_MIN;
    int solve(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            ans=max(ans,root->val);
            return root->val;
        }
        int l=solve(root->left);
        int r=solve(root->right);
        ans=max(ans,max(root->val,l+r+root->val));
        ans=max(ans,max(0,max(l,r))+root->val);
        return max(0,max(l,r))+root->val;
        
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return root->val;
        solve(root);
        return ans;
    }
    
};