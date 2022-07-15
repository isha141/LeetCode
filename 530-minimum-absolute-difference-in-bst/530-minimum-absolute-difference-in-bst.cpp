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
    int prev=-1; 
    int ans=1e9;
    private:
    int solve(TreeNode *root){
        if(root==NULL)
            return 0;
        solve(root->left);
        if(prev!=-1)
        {
            ans=min(ans,abs(root->val-prev));
        }
        prev=root->val;
         solve(root->right);
        return 0;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL)
            return 0;
         solve(root); 
        return ans;
    }
};