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
      int count=0; 
    private:
    int solve2(TreeNode *root,long long target)
    {
        if(root==NULL)
            return 0;
        if(target==root->val){
            count+=1;
        }
        solve2(root->left,target-root->val);
        solve2(root->right,target-root->val); 
        return 0;
    }
   void solve(TreeNode *root,int target)
    { 
       if(root!=NULL){ 
       solve2(root,target);
       solve(root->left,target);
       solve(root->right,target);
       }
    }
public:
    int pathSum(TreeNode* root, int target) {
        if(root==NULL)
            return 0;
        solve(root,target); 
        return count;
    }
};