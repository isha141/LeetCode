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
    vector<vector<int>>ans;
    void solve(TreeNode * root,int target,vector<int>&ds){
         if(root==NULL ){
             return;
         } 
        // cout<<root->val<<";;"<<target<<endl;
        if(target==root->val && root->left==NULL && root->right==NULL){
            ds.push_back(root->val);
            ans.push_back(ds);
            ds.pop_back();
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            return ;
        }
        ds.push_back(root->val);
        solve(root->left,target-root->val,ds);
        ds.pop_back(); 
        ds.push_back(root->val);
        solve(root->right,target-root->val,ds);
        ds.pop_back();
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(root==NULL )
            return {}; 
        vector<int>ds;
        solve(root,target,ds); 
       if(ans.size()>0) return ans;
        return {};
    } 
};  