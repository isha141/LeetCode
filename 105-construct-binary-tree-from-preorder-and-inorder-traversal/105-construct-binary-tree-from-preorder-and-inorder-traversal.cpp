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
    TreeNode *solve(int prestart,int preend,vector<int>& pre,vector<int>&in,int instart,int inend,map<int,int>&mp){
        if(prestart>preend || instart>inend)
            return NULL; 
        
        TreeNode *root=new TreeNode(pre[prestart]);
        int inroot=mp[pre[prestart]];
        int numsleft=inroot-instart;
        root->left=solve(prestart+1,prestart+numsleft,pre,in,instart,inroot-1,mp);
        root->right=solve(prestart+numsleft+1,preend,pre,in,inroot+1,inend,mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {  
        map<int,int>mp;
        for(int i=0;i<in.size();++i)
            mp[in[i]]=i;
        int n=pre.size();
        return solve(0,n-1,pre,in,0,n-1,mp);
    }
};