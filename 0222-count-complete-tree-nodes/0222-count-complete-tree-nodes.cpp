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
    void solve(TreeNode *root){
        if(root==NULL)
            return ;
        if(root)
            count++;
        solve(root->left);
        solve(root->right);
    }
public:
    int countNodes(TreeNode* root) {
         if(root==NULL)
             return 0; 
        solve(root);
        return count;
    }
};