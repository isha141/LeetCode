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
    bool solve(TreeNode * root,long long mini,long long maxi){
        if(root==NULL) return 1;
        // if(root->left==NULL && root->right==NULL)
            // return 1;
        if(root->val<=mini || root->val>=maxi)
            return 0;
        bool l=solve(root->left,mini,root->val);
        bool r=solve(root->right,root->val,maxi);
        return (l&& r);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return 1;
        if(root->left==NULL && root->right==NULL)
            return 1;
        return solve(root,LONG_MIN,LONG_MAX); 
    }
};