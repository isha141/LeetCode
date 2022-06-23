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
    int cam=0; 
    int solve(TreeNode *root){
        if(root==NULL) return -1;
        int lr=solve(root->left);
        int r=solve(root->right); 
        if(lr==0 || r==0){
            cam++;
            return 1;
        }
        else if(lr==-1 && r==-1){
            return 0;
        } 
        else 
            return -1;
            
    }
public:
    int minCameraCover(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(solve(root)==0)
            cam++;
        return cam;
    }
};