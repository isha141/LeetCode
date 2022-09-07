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
    void solve(TreeNode *root,string &s){
        if(root==NULL) return ;
        s+=to_string(root->val); 
        if(root->left)
        s+='('; 
        else if(root->right){
            s+="()";
        }
        solve(root->left,s); 
        if(root->right)
            s+='(';
        solve(root->right,s); 
        s+=')';
    }
public:
    string tree2str(TreeNode* root) {
        if(root==NULL)
            return ""; 
        string s="";
       solve(root,s); 
        s.pop_back();
        return s;
    }
};