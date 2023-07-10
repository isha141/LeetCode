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
    int ans=1e9;
    void solve(TreeNode *root,int count){
        if(root==NULL) {
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            ans=min(ans,count+1);
            return ;
        }
        solve(root->left,count+1);
       solve(root->right,count+1);
        // return min(left,right)+1;
    }
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int count=0;
         solve(root,count); 
        return ans;
    }
};