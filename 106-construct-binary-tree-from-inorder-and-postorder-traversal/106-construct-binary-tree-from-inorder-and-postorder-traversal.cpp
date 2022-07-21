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
    TreeNode *solve(int poststart,int postend,vector<int>&post,int instart,int inend,map<int,int>&mp)
    {
        if(poststart>postend || instart>inend)
            return NULL;
        int inroot=mp[post[postend]];
        int numsleft=inroot-instart;
        TreeNode *root=new TreeNode(post[postend]);
        root->left=solve(poststart,poststart+numsleft-1,post,instart,inroot-1,mp);
        root->right=solve(poststart+numsleft,postend-1,post,inroot+1,inend,mp);
        return root;

    }
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        map<int,int>mp;
        for(int i=0;i<in.size();++i)
            mp[in[i]]=i;
        return solve(0,post.size()-1,post,0,in.size()-1,mp);
    }
};