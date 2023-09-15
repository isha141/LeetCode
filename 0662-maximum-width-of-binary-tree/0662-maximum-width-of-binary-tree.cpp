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
    int ans=0;
    int solve(TreeNode *root){
        queue<pair<TreeNode *,int>>q;
        q.push({root,0});
         while(!q.empty()){
             int t=q.size();
             int mini=INT_MAX;
             int maxi=INT_MIN;
             while(t--){
                 auto itr=q.front();
                 q.pop();
                 int x=itr.second;
                 TreeNode *root=itr.first;
                 mini=min(mini,itr.second);
                 maxi=max(maxi,itr.second);
                 if(root->left)
                     q.push({root->left,2*1ll*(x-mini)+1});
                 if(root->right)
                     q.push({root->right,2*1ll*(x-mini)+2});
             }
             ans=max(ans,maxi-mini+1);
         }
        return ans;
    }
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
               return 0;
        return solve(root);
    }
};