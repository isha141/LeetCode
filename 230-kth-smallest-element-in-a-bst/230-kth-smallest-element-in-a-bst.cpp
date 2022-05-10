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
    int small(TreeNode* root, int k,int &i,int &ans)
    {
        if(root==NULL)
            return 0; 
        int l=small(root->left,k,i,ans);
        i++;
        if(k==i)
           ans=root->val;
        int r=small(root->right,k,i,ans);
        return l|| r;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)
            return 0;
        int i=0; 
        int ans=0;
         small(root,k,i,ans);
        return ans;
    }
};