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
    map<int,int>mp;
    bool solve(TreeNode* root, int k)
    {
        if(root==NULL) 
            return false; 
        bool l=solve(root->left,k); 
        mp[root->val]++;
         if(mp.count(k- root->val) && root->val!=k-root->val) 
            return true;
        bool r=solve(root->right,k);
        mp[root->val]++;
        return l || r;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) 
            return false;
        return solve(root,k);
    }
};