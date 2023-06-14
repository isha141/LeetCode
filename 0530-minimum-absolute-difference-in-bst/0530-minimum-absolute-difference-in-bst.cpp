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
    int ans=INT_MAX;
    void solve(TreeNode *root){
        if(root==NULL)
             return; 
        solve(root->left);
        if(prev==-1){
            prev=root->val;
        }
        else{
            ans=min(ans,abs(root->val-prev)); 
            prev=root->val;
        } 
        solve(root->right);
        // prev=root->val;
    }
public:
    int getMinimumDifference(TreeNode* root) {
         if(root==NULL) 
             return 0;
        solve(root);
         return ans;
    }
};