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
    bool solve(TreeNode * root,int k,int &c){
        if(root==NULL)
             return 0 ;
        solve(root->left,k,c);
        c++;
        if(c==k){
            ans=root->val; 
        }
        solve(root->right,k,c);
        return 0;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)
              return 0;
        int c=0;
        solve(root,k,c); 
        return ans;
    } 
};