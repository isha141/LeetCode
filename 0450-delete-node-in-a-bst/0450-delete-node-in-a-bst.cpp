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
    TreeNode * helper(TreeNode * root){
        while(root->right!=NULL)
              root=root->right;
        return root;
    }
    private:
    TreeNode * solve(TreeNode * root){
         if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;
        TreeNode * rightchild=root->right;
        TreeNode * lastchild=helper(root->left);
        lastchild->right=rightchild;
        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
         if(root==NULL) return root; 
        if(root->val==key)
        return solve(root); 
        TreeNode * dummy=root;
        while(root!=NULL){
            if(root->val>key){
                if(root->left!=NULL && root->left->val==key){
                    root->left=solve(root->left);
                    break;
                }
                else
                    root=root->left;
            }
            else if(root->val<key){
                if(root->right!=NULL && root->right->val==key){
                    root->right=solve(root->right); 
                    break;
                }
                else
                    root=root->right;
            }
        }
        return dummy;
    }
};