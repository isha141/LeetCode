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
    int ans=0;
    int solve(TreeNode *root)
    { 
        if(root==NULL) 
            return 0;
        int l=0;
        int r=0;
        l=solve(root->left);
        r=solve(root->right);  
        int al=0;
        int ar=0;
        if(root->left!=NULL && root->left->val==root->val)
            al+=l+1;
        if(root->right!=NULL && root->right->val==root->val)
            ar+=r+1;
        ans=max(ans,al+ar);
        return max(al,ar);
    }
        
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL) return 0; 
        solve(root);
        return ans;
    }
};