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
   TreeNode* solve(vector<int>&pre, int ind,TreeNode* root)
   { 
       if(root==NULL)
       {
           TreeNode* temp=new TreeNode(pre[ind]); 
           temp->left=NULL;
           temp->right=NULL;
           return temp;
       }
       if(pre[ind]<root->val)
           root->left=solve(pre,ind,root->left);
       else if(pre[ind]>root->val)
           root->right=solve(pre,ind,root->right);
       return root;
       
   }
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        if(pre.size()==0)
        return NULL; 
        TreeNode*  root=NULL;
        for(int i=0;i<pre.size();i++)
        root=solve(pre,i,root);
        return root;
    }
};