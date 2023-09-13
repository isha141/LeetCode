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
    TreeNode *solve(TreeNode *root,TreeNode *p,TreeNode *q){
           if(root==NULL)
                 return NULL;
           if(root->val==p->val)
                 return root;
           if(root->val==q->val)
                 return root;
           TreeNode *left=solve(root->left,p,q);
           TreeNode *right=solve(root->right,p,q);
            if(left==NULL)
                  return right;
            if(right==NULL)
                  return left;
           else
                return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          if(root==NULL)
                return root;
         return solve(root,p,q);
    }
};