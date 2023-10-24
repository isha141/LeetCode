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
    vector<int> largestValues(TreeNode* root) {
         if(root==NULL) return {};
          vector<int>ans;
          queue<TreeNode*>q;
          q.push(root);
          while(!q.empty()){
              int t=q.size();
              int maxi=INT_MIN;
              while(t--){
                  auto itr=q.front();
                  q.pop();
                  maxi=max(maxi,itr->val);
                  if(itr->left)
                      q.push(itr->left);
                  if(itr->right)
                      q.push(itr->right);
              }
              // int maxi=*max(ds.begin(),ds.end());
              ans.push_back(maxi);
          }
         return ans;
    }
};