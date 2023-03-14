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
    int solve(TreeNode * root,int value=0){ 
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) 
            return value*10+root->val; 
        int num1=0;
        int l=solve(root->left,value*10+root->val);
        int r=solve(root->right,value*10+root->val);
        return l+r;
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=solve(root); 
        return ans;
    }
};