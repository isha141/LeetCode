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
    TreeNode *solve(TreeNode *r1,TreeNode *r2){
        if(r1==NULL && r2==NULL)
              return NULL;
        if(r1==NULL)
              return r2;
        if(r2==NULL)
              return r1;
        if(r1 && r2){
            r1->val+=r2->val;
        }
        r1->left=solve(r1->left,r2->left);
        r1->right=solve(r1->right,r2->right);
        return r1;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
          return solve(root1,root2);
    }
};