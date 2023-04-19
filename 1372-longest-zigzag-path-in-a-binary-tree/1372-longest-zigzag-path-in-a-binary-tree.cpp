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
    int ans=0;
    void solve(TreeNode * root,bool flag,int c){
        if(root==NULL) return;
        ans=max(ans,c);
        if(!flag){
            solve(root->left,!flag,c+1);
            solve(root->right,1,0);
        }
        else{
            solve(root->right,!flag,c+1);
            solve(root->left,0,0);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        if(root==NULL) return 0;
        solve(root,0,0); 
        solve(root,1,0);
        return ans;
    }
};