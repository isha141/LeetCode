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
    int solve(TreeNode *root,int &sum){
        if(root==NULL) return 0;  
        if(root->left==NULL && root->right==NULL)
            return root->val;
         int temp=solve(root->left,sum);
        sum+=temp;
        solve(root->right,sum); 
        return 0;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        solve(root,sum);
        return sum;
    }
};