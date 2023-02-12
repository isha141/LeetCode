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
    TreeNode * solve(int prestart,int preend,int instart,int inend,vector<int>&pre,vector<int>&in,map<int,int>&mp){
        if(prestart>preend|| instart>inend)
            return NULL;
        
        TreeNode* root=new TreeNode(pre[prestart]); 
        int inroot=mp[pre[prestart]]; 
        int numsleft=inroot-instart;
        root->left=solve(prestart+1,prestart+numsleft,instart,inroot-1,pre,in,mp);
        root->right=solve(prestart+numsleft+1,preend,inroot+1,inend,pre,in,mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=in.size();
        TreeNode* root;
        map<int,int>mp;
        for(int i=0;i<n;++i){
            mp[in[i]]=i;
        }
        root=solve(0,n-1,0,n-1,pre,in,mp);
        return root;
    }
};