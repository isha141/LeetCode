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
    bool ok(TreeNode *root,TreeNode *sub){
        if(root==NULL)
             return sub==NULL;
        if(sub==NULL) return 0;
        if(root->val!=sub->val)
            return  0;
        if(ok(root->left,sub->left) ==0 || ok(root->right,sub->right)==0)
              return 0;
        return 1;
    }
    bool solve(TreeNode *root,TreeNode *sub){
        if(root==NULL)
             return 0;
        // bool l=0;
        // bool r=0;
        if(root && sub && root->val==sub->val)
            if(ok(root,sub))
                return 1;
        bool l=solve(root->left,sub);
        bool r=solve(root->right,sub);
        return (l||r);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if(root==NULL)
            return sub==NULL;
        if(sub==NULL)
               return 1;
        
         return solve(root,sub);
    }
};