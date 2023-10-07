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
      map<int,int>mp;
    TreeNode* solve(int prestart,int preend,vector<int>&pre,int instart,int inend){
            if(prestart>preend || instart>inend)
                  return NULL;
            TreeNode *root=new TreeNode(pre[prestart]); 
            int inroot=mp[root->val];
            int numsleft=inroot-instart;
            root->left=solve(prestart+1,prestart+numsleft,pre,instart,inroot-1);
            root->right=solve(prestart+numsleft+1,preend,pre,inroot+1,inend);
            return root;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
           int n=pre.size(); 
           for(int i=0;i<n;++i){
               mp[in[i]]=i;
           }
           return solve(0,n-1,pre,0,n-1);
    }
};