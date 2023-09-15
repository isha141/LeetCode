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
    int n;
    map<int,int>mp;
    TreeNode *solve(vector<int>&pre,vector<int>&post,int &preindex,int start,int end){
        if(preindex>=n  || start>end)
               return NULL;
        TreeNode *root=new TreeNode(pre[preindex++]);
        if(preindex>=n || start==end)
              return root;
        int last=mp[pre[preindex]];
        root->left=solve(pre,post,preindex,start,last);
        root->right=solve(pre,post,preindex,last+1,end-1);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
          int preindex=0;
           n=pre.size();
          for(int i=0;i<n;++i){
              mp[post[i]]=i;
          }
        return solve(pre,post,preindex,0,n-1);
    }
};