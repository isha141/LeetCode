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
     vector<TreeNode*>ans;
    map<string,int>mp;  
    string ok(TreeNode* root){
        if(root==NULL)
             return "#";
        return to_string(root->val)+'('+ok(root->left)+ok(root->right)+')';
    }
    void solve(TreeNode* root){
        if(root==NULL)
            return ;
        string temp=ok(root);
        mp[temp]++;
         if(mp[temp]==2){
            ans.push_back(root);
        }
        solve(root->left);
        solve(root->right);
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root==NULL)
             return ans;
        solve(root);
        return ans;
    }
};