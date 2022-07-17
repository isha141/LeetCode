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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode *>s;
        if(root==NULL) return ans;
        while(!s.empty() || root!=NULL){
            if(root){
                s.push(root);
                root=root->left;
            }
            else{
                TreeNode *temp=s.top()->right;  
                if(temp==NULL){  
                   temp=s.top(); 
                  ans.push_back(temp->val);
                    s.pop();
                    while(!s.empty() &&  temp==s.top()->right){
                        temp=s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                    root=temp;
            }
        }
        return ans;
    }
};