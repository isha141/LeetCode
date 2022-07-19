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
    void solve(TreeNode *root,int target,vector<int>&ds,vector<vector<int>>&ans,int sum)
    {
        if(!root) return;
        ds.push_back(root->val);
        if(root->left==NULL && root->right==NULL && sum==root->val){
                ans.push_back(ds);
        }
        sum-=root->val;
        solve(root->left,target,ds,ans,sum);
        solve(root->right,target,ds,ans,sum);
        ds.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
       vector<vector<int>>ans;
        vector<int>ds;
        if(root==NULL) 
            return ans;
        solve(root,target,ds,ans,target);
        return ans;
    }
};
