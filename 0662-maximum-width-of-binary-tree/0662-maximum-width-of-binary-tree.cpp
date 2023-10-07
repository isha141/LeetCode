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
    int solve(TreeNode *root){
        queue<pair<TreeNode *,int>>q; // root,index;
        int ans=0;
        q.push({root,0});
        while(!q.empty()){
              int t=q.size();
              int mini=q.front().second;
              int leftIndex=INT_MAX;
              int rightIndex=INT_MIN;
            while(t--){
                auto itr=q.front();
                q.pop();
                TreeNode *node=itr.first;
                // cout<<node->val<<"-->";
                int index=itr.second;
                leftIndex=min(leftIndex,index);
                rightIndex=max(rightIndex,index);
                if(node->left!=NULL){
                  q.push({node->left,2*1ll*(index-mini)+1});  
                }
                if(node->right!=NULL){
                    q.push({node->right,2*1ll*(index-mini)+2});
                }
            } 
            // cout<<endl;
            ans=max(ans,rightIndex-leftIndex+1);
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