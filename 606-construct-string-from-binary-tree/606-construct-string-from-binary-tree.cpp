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
    void solve(TreeNode *root,string &temp){
        if(root==NULL)
            return ; 
        temp+=to_string(root->val);
        if(root->left){
         temp+='(';
         solve(root->left,temp);
         temp+=')';
        }
        if(root->right){
            if(root->left==NULL){
                temp+="()";
            }
       temp+='(';
       solve(root->right,temp);
       temp+=')';
        }
    }
public:
    string tree2str(TreeNode* root) {
        string temp="";
        solve(root,temp);
         return temp;  
    }
};