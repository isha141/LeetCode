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
    bool solve(TreeNode *root,int target,int sum){ 
        if(root==NULL) return 0;
        if(root && root->left==NULL && root->right==NULL)
        {
            if(sum+root->val==target)
                return 1;
            return 0;
            
        }
        sum+=root->val;
        bool l=solve(root->left,target,sum);
        bool r=solve(root->right,target,sum);
            return l||r; 
    }
public:
    bool hasPathSum(TreeNode* root, int target) { 
        int sum=0; 
        if(root==NULL) return 0;
        return solve(root,target,sum);
    }
};