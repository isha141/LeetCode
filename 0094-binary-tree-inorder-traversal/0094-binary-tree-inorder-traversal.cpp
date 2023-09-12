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
      void solve(TreeNode *root,vector<int>&ans){ 
            stack<TreeNode*>s;
             // s.push(root); 
             // for(auto iit: ans)
                   // cout<<iit<<";;;"<<endl;
             while(1){
                   while(root!=NULL){
                       s.push(root);
                       root=root->left;
                   }
                 if(s.empty()){
                     return;
                 }
                 else{
                     auto itr=s.top();
                      s.pop();
                     ans.push_back(itr->val);
                      root=itr->right;
                 }
             }
          return ;
      }
public:
    vector<int> inorderTraversal(TreeNode* root) { 
          if(root==NULL)
                return {};
           vector<int>ans;
           solve(root,ans);
           return ans;
    }
};