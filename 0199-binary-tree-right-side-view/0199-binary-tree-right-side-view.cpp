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
         queue<TreeNode *>q;
          q.push(root);
          map<int,int>mp;
        int level=0;
           while(!q.empty()){
               int t=q.size();
               while(t--){
                   auto itr=q.front();
                   q.pop();
                    mp[level]=itr->val;
                    if(itr->left)
                         q.push(itr->left);
                    if(itr->right)
                         q.push(itr->right);
               }
               ans.push_back(mp[level]);
                level+=1;
           }
         return ;
    }
public:
    vector<int> rightSideView(TreeNode* root) {
          if(root==NULL)
                return {};
          vector<int>ans;
         solve(root,ans);
          return ans;
    }
};