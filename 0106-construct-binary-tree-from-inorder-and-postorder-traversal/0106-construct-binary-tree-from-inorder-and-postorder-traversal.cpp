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
    map<int,int>mp;
    TreeNode *solve(int prestart,int preend,vector<int>&post,int instart,int inend){
        if(prestart>preend  || instart>inend)
              return NULL;
        TreeNode *root=new TreeNode(post[preend]);
        int inroot=mp[root->val];
        int numsleft=inroot-instart;
        root->left=solve(prestart, prestart+numsleft-1,post,instart,inroot-1);
        root->right=solve(prestart+numsleft,preend-1,post,inroot+1,inend);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
          int n=in.size();
          for(int i=0;i<n;++i){
            mp[in[i]]=i;
          } 
          return solve(0,n-1,post,0,n-1);
    }
};