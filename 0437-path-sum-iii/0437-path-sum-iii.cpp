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
     map<long,int>mp;
     void solve(TreeNode *root,long target,long sum){
         if(root==NULL)
               return;
         sum+=root->val;
         if(sum==target){
              ans+=1;
         }
         if(mp.find(sum-target)!=mp.end())
               ans+=mp[sum-target];
          // cout<<sum<<" ;; "<<root->val<<endl;
          mp[sum]+=1; 
          // cout<<mp[sum]<<" --> "<<endl;
         solve(root->left,target,sum);
         solve(root->right,target,sum);
          mp[sum]-=1;
         return ;
     }
public:
    int pathSum(TreeNode* root, int target) {
          if(root==NULL)
               return 0;
           solve(root,target,0);
          return ans;
    }
};