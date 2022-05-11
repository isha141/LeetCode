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
    TreeNode* solve(vector<int>& pre,int &ind,int &upper)
    {
        if(ind==pre.size() || pre[ind]>upper)
            return  NULL;
        TreeNode*  root=new  TreeNode(pre[ind++]); 
        root->left=solve(pre,ind,root->val);
        root->right=solve(pre,ind,upper);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        if(pre.size()==0)
            return NULL; 
        int upper=INT_MAX; 
        int i=0;
        return solve(pre,i,upper);
    }
};