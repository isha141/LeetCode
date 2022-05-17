/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution { 
    private:
    void solve(TreeNode* root,TreeNode* target,TreeNode* &ans)
    {
        if(root==NULL)
            return ; 
        if(root->val==target->val)
            ans=root;
        solve(root->left,target,ans);
        solve(root->right,target,ans); 
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) { 
        if(cloned==NULL)
            return NULL; 
        TreeNode* ans=NULL;
         solve(cloned,target,ans);
        // return ans;
        return ans;
    }
};