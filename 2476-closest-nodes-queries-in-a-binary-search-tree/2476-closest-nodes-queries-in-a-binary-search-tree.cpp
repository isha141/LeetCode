/**
 * Definition for a binary tree node.
 * struct TreeNode 
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution { 
    void solve(TreeNode* root,vector<int>&ds){
         if(root==NULL)
             return ;
        solve(root->left,ds);
        ds.push_back(root->val);
        solve(root->right,ds);
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans; 
        vector<int>ds;
        solve(root,ds);
        int n=ds.size();
        for(auto itr: q){
            auto it=lower_bound(ds.begin(),ds.end(),itr);
            if(it!=end(ds) && *it==itr){
                ans.push_back({itr,itr});
            }
            else{
                ans.push_back({it==begin(ds)?-1:*prev(it),it==end(ds)?-1:*(it)});
            }
        }
        return ans;
    }
};