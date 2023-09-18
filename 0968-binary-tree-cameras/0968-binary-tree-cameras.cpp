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
    int ans=0;
    int solve(TreeNode *root){
        if(root==NULL)
             return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        if(l==-1|| r==-1){
            ans+=1;
            return 1;
        }
        else if(l==1 || r==1){
            return 0;
        }
        else
            return -1;
    }
public:
    int minCameraCover(TreeNode* root) {
        if(root==NULL)
              return 0;
        int temp= solve(root);
        if(temp==-1){
            ans+=1;
        }
        return ans;
    }
};