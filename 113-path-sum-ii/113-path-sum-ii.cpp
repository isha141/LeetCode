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
    void solve(TreeNode *root,vector<int>ds,vector<vector<int>>&ans,int target)
    {
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL && target==root->val){
            ds.push_back(root->val);
            ans.push_back(ds);
            ds.pop_back();
            return ;
        }
        ds.push_back(root->val);
        solve(root->left,ds,ans,target-root->val);
        // ds.pop_back();
        solve(root->right,ds,ans,target-root->val);
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(root==NULL)
            return {};
        vector<vector<int>>ans; 
        vector<int>ds;
        solve(root,ds,ans,target); 
        return ans;
    }
};