class Solution { 
    private: 
    int count=0;
    int solve(TreeNode *root,int mini)
    { 
        if(root==NULL)
            return 0; 
        mini=max(mini,root->val);
        solve(root->left,mini);
        if(root->val==mini)
            count+=1;
        solve(root->right,mini);
        return 0;
    }
public:
    int goodNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
       solve(root,root->val);
        return count;
    }
};