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
    void solve(TreeNode *root,vector<vector<int>>&ans,int target,vector<int>ds,int sum)
    {   
           if(root==NULL){
          return ;
         }
        if(root->left==NULL &&  root->right==NULL){
             if(target-sum==root->val){ 
                 ds.push_back(root->val);
            ans.push_back(ds);
            ds.clear();
            return ;
          } 
            return ;
        }
        sum+=root->val;
        ds.push_back(root->val);
        solve(root->left,ans,target,ds,sum);  
        solve(root->right,ans,target,ds,sum); 
        return ;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        if(root==NULL) return ans; 
        vector<int>ds;
        int sum=0;
        solve(root,ans,target,ds,sum); 
        return ans;
    }
};